#include "Thread.h"


//http://antonym.org/2009/05/threading-with-boost---part-i-creating-threads.html

namespace System{
	namespace Threading{

		ThreadStart::ThreadStart()
		{
		}

		ThreadStart::ThreadStart(boost::function<void ()> target)
		{
			this->functor = target;
		}

		ThreadStart::operator boost::function<void ()>()
		{
			return this->functor;
		}

		ParameterizedThreadStart::ParameterizedThreadStart()
		{
		}

		ParameterizedThreadStart::ParameterizedThreadStart(boost::function<void (Object*)> target)
		{
			this->functor = target;
		}

		ParameterizedThreadStart::operator boost::function<void (Object*)>()
		{
			return this->functor;
		}

		Thread::Thread(ThreadStart* target)
		{			
			functor = *target;
			internalFunctor = ThreadStart(DELEGATE_FUNC(Thread::collectableThread));
			
			GC_get_stack_base(&sb);
		}

		Thread::Thread(ParameterizedThreadStart* target)
		{			
			paramFunctor = *target;
			internalParamFunctor = ParameterizedThreadStart(DELEGATE_FUNC(Thread::collectableParamThread, _1));
			
			GC_get_stack_base(&sb);
		}

		void Thread::Sleep(int milliseconds)
		{
			//<ÑAPA>
			if(milliseconds < 0) while(1){}			
			//</ÑAPA>

			boost::posix_time::milliseconds sleepTime(milliseconds);
			boost::this_thread::sleep(sleepTime);
		}

		void Thread::Sleep(TimeSpan* span)
		{
			boost::posix_time::milliseconds sleepTime(span->TotalMilliseconds);
			boost::this_thread::sleep(sleepTime);
		}

		void Thread::Start()
		{	
			workerThread = boost::thread(this->internalFunctor.functor);
		}

		void Thread::Start(Object* obj)
		{	
			workerThread = boost::thread(this->internalParamFunctor.functor, obj);
		}

		void Thread::Join()
		{
			workerThread.join();
		}

		void Thread::Abort()
		{
			workerThread.interrupt();
		}

		void Thread::collectableThread()
		{			
			GC_register_my_thread(&sb);
			this->functor.functor();
			GC_unregister_my_thread();
		}

		void Thread::collectableParamThread(Object* param)
		{
			GC_register_my_thread(&sb);
			this->paramFunctor.functor(param);
			GC_unregister_my_thread();
		}
	}
}
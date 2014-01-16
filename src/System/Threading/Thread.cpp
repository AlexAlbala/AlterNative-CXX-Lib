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
		}

		Thread::Thread(ParameterizedThreadStart* target)
		{			
			param_functor = *target;
		}

		inline void Thread::Sleep(int milliseconds)
		{
			//TO BE IMPROVED...
			if(milliseconds < 0) while(1){}			

			boost::posix_time::milliseconds sleepTime(milliseconds);
			boost::this_thread::sleep(sleepTime);
		}

		inline void Thread::Sleep(TimeSpan* span)
		{
			boost::posix_time::milliseconds sleepTime(span->TotalMilliseconds);
			boost::this_thread::sleep(sleepTime);
		}

		inline void Thread::Start()
		{	
			workerThread = boost::thread(this->functor.functor);
		}

		inline void Thread::Start(Object* obj)
		{	
			workerThread = boost::thread(this->param_functor.functor, obj);
		}

		inline void Thread::Join()
		{
			workerThread.join();
		}

		inline void Thread::Abort()
		{
			workerThread.interrupt();
		}
	}
}
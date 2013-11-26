#include "Thread.h"
#include "../Exception/SystemException/NotImplementedException.h"


//http://antonym.org/2009/05/threading-with-boost---part-i-creating-threads.html

namespace System{
	namespace Threading{

		/*Thread::Thread(ThreadStart* del)
		{			
			//functor = &del->_target;
		}*/

		void Thread::Sleep(int milliseconds)
		{
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
			//NOT WORKING!!
			//workerThread = boost::thread(this->functor);
		}

		void Thread::Join()
		{
			workerThread.join();
		}

		void Thread::Abort()
		{
			workerThread.interrupt();
		}
	}
}
#pragma once
#include "../System.h"
#include "../Delegate.h"
#include "../TimeSpan.h"
#include <boost/thread.hpp>

namespace System{
	namespace Threading{
				
		class ThreadStart : public Delegate
		{
			friend class Thread;
		public:
			ThreadStart(boost::function<void()> target);			

		private:
			ThreadStart();
			boost::function<void ()> functor;
			operator boost::function<void()>();
		};


		class Thread : public virtual Object, public virtual gc_cleanup{
		private:
			boost::thread workerThread;
			ThreadStart functor;
		public:
			Thread(ThreadStart* target);
			void Start();
			void Join();
			void Abort();
			static void Sleep(int milliseconds);
			static void Sleep(TimeSpan* time);
		};
	}
}
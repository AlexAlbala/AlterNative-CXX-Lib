#pragma once
#include "../System.h"
#include "../Delegate.h"
#include "../TimeSpan.h"
#include <boost/thread.hpp>

namespace System{
	namespace Threading{

				
		
		class Thread : public virtual Object, public virtual gc_cleanup{
		private:
			boost::thread workerThread;
			//signal<void ()>* functor;
		public:
			void Start();
			void Join();
			void Abort();
			static void Sleep(int milliseconds);
			static void Sleep(TimeSpan* time);
		};
	}
}
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

		class ParameterizedThreadStart : public Delegate
		{
			friend class Thread;
		public:
			ParameterizedThreadStart(boost::function<void (System::Object*)> target);

		private:
			ParameterizedThreadStart();
			boost::function<void (System::Object*)> functor;
			operator boost::function<void (System::Object*)>();
		};


		class Thread : public virtual Object
		{
		private:
			boost::thread workerThread;
			ThreadStart functor;
			ParameterizedThreadStart param_functor;
		public:
			Thread(ThreadStart* target);
			Thread(ParameterizedThreadStart* target);
			void Start();
			void Start(Object* obj);
			void Join();
			void Abort();
			static void Sleep(int milliseconds);
			static void Sleep(TimeSpan* time);
		};
	}
}
#pragma once
#include "../System.h"
//#include "MarshalByRefObject.h"
#include "../IDisposable.h"
//#include "TimerHolder.h"
#include "../Exception/SystemException/ArgumentException/ArgumentNullException.h"
#include "../Exception/SystemException/ArgumentException/ArgumentOutOfRangeException.h"
//#include "Environment.h"
#include "StackCrawlMark.h"
#include "../TimeSpan.h"
//#include "WaitHandle.h"
#include "../GC.h"
//#include "TimerQueueTimer.h"
#include "../Delegate.h"
#include <boost/asio.hpp>

//using namespace System::Runtime::InteropServices;
//using namespace System::Security::Permissions;
using namespace System;
//using namespace System::Security;
//using namespace System::Runtime::CompilerServices;
namespace System {
	namespace Threading {

		class TimerCallback
		{
			/** for using Timercallback as a waitHandle:

			1- http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference/Handler.html
			2- http://en.cppreference.com/w/cpp/concept/CopyConstructible

			**/

			friend class Timer;
		public:
			TimerCallback(boost::function<void (System::Object*)> target);
			void operator()(const boost::system::error_code& ec);

		private:
			TimerCallback();
			boost::function<void (System::Object*)> functor;
			operator boost::function<void (System::Object*)>();
		};


		/**** TOTALLY TRANSLATED BY ALTERNATIVE (only changes the call to boost asio timers ****/
		//Attribute: __DynamicallyInvokable*
		//Attribute: ComVisible*(true)
		//Attribute: HostProtection*(SecurityAction::LinkDemand, Synchronization = true, ExternalThreading = true)
		class Timer : /*public virtual MarshalByRefObject,*/ public virtual IDisposable, public virtual Object{
			private:
				boost::asio::io_service* m_serv;
				boost::asio::deadline_timer* m_timer;
				TimerCallback* callback;
			private:
				uint MAX_SUPPORTED_TIMEOUT;
				void Restart(int period, int dueTime);
			//Attribute: __DynamicallyInvokable*
			//Attribute: SecuritySafeCritical*
			//Attribute: MethodImpl*(MethodImplOptions::NoInlining)
			public:
				Timer(TimerCallback* callback, Object* state, int dueTime, int period);
			//Attribute: __DynamicallyInvokable*
			//Attribute: SecuritySafeCritical*
			//Attribute: MethodImpl*(MethodImplOptions::NoInlining)
			public:
				Timer(TimerCallback* callback, Object* state, TimeSpan* dueTime, TimeSpan* period);
			//Attribute: CLSCompliant*(false)
			//Attribute: SecuritySafeCritical*
			//Attribute: MethodImpl*(MethodImplOptions::NoInlining)
			public:
				Timer(TimerCallback* callback, Object* state, uint dueTime, uint period);
			//Attribute: SecuritySafeCritical*
			//Attribute: MethodImpl*(MethodImplOptions::NoInlining)
			public:
				Timer(TimerCallback* callback, Object* state, long dueTime, long period);
			//Attribute: SecuritySafeCritical*
			//Attribute: MethodImpl*(MethodImplOptions::NoInlining)
			public:
				Timer(TimerCallback* callback);
			//Attribute: __DynamicallyInvokable*
			public:
				bool Change(int dueTime, int period);
			//Attribute: __DynamicallyInvokable*
			public:
				bool Change(TimeSpan* dueTime, TimeSpan* period);
			//Attribute: CLSCompliant*(false)
			public:
				bool Change(uint dueTime, uint period);
			public:
				bool Change(long dueTime, long period);
			public:
				//bool Dispose(WaitHandle* notifyObject);
			//Attribute: __DynamicallyInvokable*
			public:
				void Dispose();
			public:
				void KeepRootedWhileScheduled();
			//Attribute: SecurityCritical*
			private:
				void TimerSetup(TimerCallback* callback, Object* state, uint dueTime, uint period, StackCrawlMark* stackMark);
		};
	}
}
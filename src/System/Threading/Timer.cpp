/**** TOTALLY TRANSLATED BY ALTERNATIVE (only changes the call to boost asio timers ****/
#include "Timer.h"
#include "Thread.h"

namespace System {
	namespace Threading {
		
		TimerCallback::TimerCallback(boost::function<void (System::Object*)> target)
		{
			this->functor = target;
		}
		
		void TimerCallback::operator()(const boost::system::error_code& ec)
		{
			this->functor(new Object());
		}
		
		TimerCallback::TimerCallback()
		{			
		}		
		
		TimerCallback::operator boost::function<void (System::Object*)>()
		{
			return this->functor;
		}

		//Attribute: __DynamicallyInvokable*
		//Attribute: SecuritySafeCritical*
		//Attribute: MethodImpl*(MethodImplOptions::NoInlining)
		Timer::Timer(TimerCallback* callback, Object* state, int dueTime, int period){
			MAX_SUPPORTED_TIMEOUT = 4294967294u;
			if (dueTime < -1){
				throw new ArgumentOutOfRangeException(new String("dueTime"), new String("ArgumentOutOfRange_NeedNonNegOrNegative1e"));
				//throw new ArgumentOutOfRangeException(new String("dueTime"), Environment::GetResourceString(new String("ArgumentOutOfRange_NeedNonNegOrNegative1")));
			}
			if (period < -1) {
				throw new ArgumentOutOfRangeException(new String("period"), new String("ArgumentOutOfRange_NeedNonNegOrNegative1"));
				//throw new ArgumentOutOfRangeException(new String("period"), Environment::GetResourceString(new String("ArgumentOutOfRange_NeedNonNegOrNegative1")));
			}
			StackCrawlMark stackCrawlMark = StackCrawlMark::LookForMyCaller;
			this->TimerSetup(callback, state, (uint)(dueTime), (uint)(period), &stackCrawlMark);
		}
		//Attribute: __DynamicallyInvokable*
		//Attribute: SecuritySafeCritical*
		//Attribute: MethodImpl*(MethodImplOptions::NoInlining)
		Timer::Timer(TimerCallback* callback, Object* state, TimeSpan* dueTime, TimeSpan* period){
			long num = (long)(dueTime->TotalMilliseconds);
			if (num < -1L){
				throw new ArgumentOutOfRangeException(new String("dueTm"), new String("ArgumentOutOfRange_NeedNonNegOrNegative1"));
				//throw new ArgumentOutOfRangeException(new String("dueTm"), Environment::GetResourceString(new String("ArgumentOutOfRange_NeedNonNegOrNegative1")));
			}
			/*if (num > (long)((ulong)(-2))) {
				throw new ArgumentOutOfRangeException(new String("dueTm"), new String("ArgumentOutOfRange_TimeoutTooLarge"));
				//throw new ArgumentOutOfRangeException(new String("dueTm"), Environment::GetResourceString(new String("ArgumentOutOfRange_TimeoutTooLarge")));
			}*/
			long num2 = (long)(period->TotalMilliseconds);
			if (num2 < -1L) {
				throw new ArgumentOutOfRangeException(new String("periodTm"), new String("ArgumentOutOfRange_NeedNonNegOrNegative1"));
				//throw new ArgumentOutOfRangeException(new String("periodTm"), Environment::GetResourceString(new String("ArgumentOutOfRange_NeedNonNegOrNegative1")));
			}
			/*if (num2 > (long)((ulong)(-2))) {
				throw new ArgumentOutOfRangeException(new String("periodTm"), new String("ArgumentOutOfRange_PeriodTooLarge"));
				//throw new ArgumentOutOfRangeException(new String("periodTm"), Environment::GetResourceString(new String("ArgumentOutOfRange_PeriodTooLarge")));
			}*/
			StackCrawlMark stackCrawlMark = StackCrawlMark::LookForMyCaller;
			this->TimerSetup(callback, state, (uint)(num), (uint)(num2), &stackCrawlMark);
		}
		//Attribute: CLSCompliant*(false)
		//Attribute: SecuritySafeCritical*
		//Attribute: MethodImpl*(MethodImplOptions::NoInlining)
		Timer::Timer(TimerCallback* callback, Object* state, uint dueTime, uint period){
			StackCrawlMark stackCrawlMark = StackCrawlMark::LookForMyCaller;
			this->TimerSetup(callback, state, dueTime, period, &stackCrawlMark);
		}
		//Attribute: SecuritySafeCritical*
		//Attribute: MethodImpl*(MethodImplOptions::NoInlining)
		Timer::Timer(TimerCallback* callback, Object* state, long dueTime, long period)
		{
			if (dueTime < -1L){
				throw new ArgumentOutOfRangeException(new String("dueTime"), new String("ArgumentOutOfRange_NeedNonNegOrNegative1"));
				//throw new ArgumentOutOfRangeException(new String("dueTime"), Environment::GetResourceString(new String("ArgumentOutOfRange_NeedNonNegOrNegative1")));
			}
			if (period < -1L) {
				throw new ArgumentOutOfRangeException(new String("period"), new String("ArgumentOutOfRange_NeedNonNegOrNegative1"));
				//throw new ArgumentOutOfRangeException(new String("period"), Environment::GetResourceString(new String("ArgumentOutOfRange_NeedNonNegOrNegative1")));
			}
			/*if (dueTime > (long)((ulong)(-2))) {
				throw new ArgumentOutOfRangeException(new String("dueTime"), new String("ArgumentOutOfRange_TimeoutTooLarge"));
				//throw new ArgumentOutOfRangeException(new String("dueTime"), Environment::GetResourceString(new String("ArgumentOutOfRange_TimeoutTooLarge")));
			}
			if (period > (long)((ulong)(-2))) {
				throw new ArgumentOutOfRangeException(new String("period"), new String("ArgumentOutOfRange_PeriodTooLarge"));
				//throw new ArgumentOutOfRangeException(new String("period"), Environment::GetResourceString(new String("ArgumentOutOfRange_PeriodTooLarge")));
			}*/
			StackCrawlMark stackCrawlMark = StackCrawlMark::LookForMyCaller;
			this->TimerSetup(callback, state, (uint)(dueTime), (uint)(period), &stackCrawlMark);
		}
		//Attribute: SecuritySafeCritical*
		//Attribute: MethodImpl*(MethodImplOptions::NoInlining)
		Timer::Timer(TimerCallback* callback){
			int dueTime = -1;
			int period = -1;
			StackCrawlMark stackCrawlMark = StackCrawlMark::LookForMyCaller;
			this->TimerSetup(callback, this, (uint)(dueTime), (uint)(period), &stackCrawlMark);
		}
		//Attribute: __DynamicallyInvokable*
		bool Timer::Change(int dueTime, int period){
			if (dueTime < -1){
				throw new ArgumentOutOfRangeException(new String("dueTime"), new String("ArgumentOutOfRange_NeedNonNegOrNegative1"));
				//throw new ArgumentOutOfRangeException(new String("dueTime"), Environment::GetResourceString(new String("ArgumentOutOfRange_NeedNonNegOrNegative1")));
			}
			if (period < -1) {
				throw new ArgumentOutOfRangeException(new String("period"), new String("ArgumentOutOfRange_NeedNonNegOrNegative1"));
				//throw new ArgumentOutOfRangeException(new String("period"), Environment::GetResourceString(new String("ArgumentOutOfRange_NeedNonNegOrNegative1")));
			}
			this->Restart(period,dueTime);

			return true;
			//return this->m_timer->m_timer->Change((uint)(dueTime), (uint)(period));
		}
		//Attribute: __DynamicallyInvokable*
		bool Timer::Change(TimeSpan* dueTime, TimeSpan* period){
			return this->Change((long)(dueTime->TotalMilliseconds), (long)(period->TotalMilliseconds));
		}
		//Attribute: CLSCompliant*(false)
		bool Timer::Change(uint dueTime, uint period){
			this->Restart(period,dueTime);

			return true;
			//return this->m_timer->m_timer->Change(dueTime, period);
		}
		bool Timer::Change(long dueTime, long period)
		{
			if (dueTime < -1L) {
				throw new ArgumentOutOfRangeException(new String("dueTime"), new String("ArgumentOutOfRange_NeedNonNegOrNegative1"));
				//throw new ArgumentOutOfRangeException(new String("dueTime"), Environment::GetResourceString(new String("ArgumentOutOfRange_NeedNonNegOrNegative1")));
			}
			if (period < -1L) {
				throw new ArgumentOutOfRangeException(new String("period"), new String("ArgumentOutOfRange_NeedNonNegOrNegative1"));
				//throw new ArgumentOutOfRangeException(new String("period"), Environment::GetResourceString(new String("ArgumentOutOfRange_NeedNonNegOrNegative1")));
			}
			/*if (dueTime > (long)((ulong)(-2))) {
				throw new ArgumentOutOfRangeException(new String("dueTime"), new String("ArgumentOutOfRange_TimeoutTooLarge"));
				//throw new ArgumentOutOfRangeException(new String("dueTime"), Environment::GetResourceString(new String("ArgumentOutOfRange_TimeoutTooLarge")));
			}
			if (period > (long)((ulong)(-2))) {
				throw new ArgumentOutOfRangeException(new String("period"), new String("ArgumentOutOfRange_PeriodTooLarge"));
				//throw new ArgumentOutOfRangeException(new String("period"), Environment::GetResourceString(new String("ArgumentOutOfRange_PeriodTooLarge")));
			}*/

			this->Restart(period,dueTime);

			return true;
			//return this->m_timer->m_timer->Change((uint)(dueTime), (uint)(period));
		}
		/*bool Timer::Dispose(WaitHandle* notifyObject)
		{
			if (notifyObject == null) {
				throw new ArgumentNullException(new String("notifyObject"));
			}
			return this->m_timer->Close(notifyObject);
		}*/
		//Attribute: __DynamicallyInvokable*
		void Timer::Dispose(){
			this->m_timer->cancel();
			m_serv->stop();
			m_timer = null;
			delete internalCallback;
			delete callback;			
		}
		void Timer::KeepRootedWhileScheduled()
		{			
			//GC::SuppressFinalize(this->m_timer);
		}

		//Attribute: SecurityCritical*
		/*void Timer::TimerSetup(TimerCallback* callback, Object* state, uint dueTime, uint period, StackCrawlMark* stackMark){
			if (callback == null){
				throw new ArgumentNullException(new String("TimerCallback"));
			}
			this->m_timer = new TimerHolder(new TimerQueueTimer(callback, state, dueTime, period, stackMark));
		}*/

		void Timer::TimerSetup(TimerCallback* callback, Object* state, uint dueTime, uint period, StackCrawlMark* stackMark){
			if (callback == null){
				throw new ArgumentNullException(new String("TimerCallback"));
			}
			
			this->callback = callback;
			this->Restart(period, dueTime);
		}

		void Timer::Restart(int period, int dueTime)
		{
			if(m_timer != null) 
			{
				m_timer->cancel();
				delete m_timer;
			}

			if(m_serv != null)
			{
				delete m_serv;
			}

			if(internalCallback != null)
			{
				delete internalCallback;
			}

			if(period < 0 || dueTime < 0)
				return;

			
			this->actualPeriod = period;
			this->internalCallback = new TimerCallback(DELEGATE_FUNC(Timer::extend, _1));
			m_serv = new boost::asio::io_service();
			m_timer = new boost::asio::deadline_timer(*m_serv, boost::posix_time::milliseconds(dueTime));
			m_timer->async_wait(*internalCallback);

			boost::thread bt(boost::bind(&boost::asio::io_service::run, m_serv));
		}

		void Timer::extend(Object* state)
		{
			m_timer->expires_at(m_timer->expires_at() + boost::posix_time::milliseconds(actualPeriod));
			m_timer->async_wait(*internalCallback);

			Thread* execThread = new Thread(new ParameterizedThreadStart(callback->functor));
			execThread->Start(state);
		}
	}
}
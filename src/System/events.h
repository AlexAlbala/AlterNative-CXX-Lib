#pragma once
#include "Delegate.h"

namespace __Internal__{
	template<typename A, typename... B>
	class _event;

	class Event
	{
	public:
		template<typename A, typename... B>
		static Event* CreateEvent(__Internal__::_Delegate<A,B...>* del)
		{
			_event<A, B..>* ev = new _event<A,B..>();
			ev->setDelegate(del);
			return dynamic_cast<Event*>(ev);
		}

		template<typename A, typename... B>
		void fireEvent(_event<A,B...> ev, B... args)
		{
			ev->fireEvent(args...);
		}
	};

	template<typename A, typename... B>
	class _event : public Event
	{
	private:
		__Internal__::_Delegate<A,B...>* internalDelegate;

	public:
		void setDelegate(__Internal__::_Delegate<A,B...>* internalDelegate)
		{		
			this->internalDelegate = internalDelegate;
		}

		_event& operator += (const _event& other)
		{	
			internalDelegate = System::Delegate::Combine(internalDelegate, other.internalDelegate);
			return *this;
		}
		
		_event& operator -= (const _event& other)
		{
			//TODO
			return *this;
		}

	protected:
		void fireEvent(B... args) 
		{
			internalDelegate->Invoke(args...);
		}		
	};	
}

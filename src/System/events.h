#pragma once
#include "Delegate.h"

namespace __Internal__{
	template<typename A, typename... B>
	class _event;

	class Event
	{
	public:
		template<typename A, typename... B>
		static _event<A, B...> CreateEvent(__Internal__::_Delegate<A,B...>* del)
		{
			_event<A, B...>* ev = new _event<A,B...>();

			if(del != null)
			{
				ev->setDelegate(del);
			}
			return *(ev);
		}
	};

	template<typename A, typename... B>
	class _event : public Event
	{
	private:
		__Internal__::_Delegate<A,B...>* internalDelegate;

	public:

		_event()
		{
			internalDelegate = null;
		}

		~_event()
		{
			delete internalDelegate;
		}

		void setDelegate(__Internal__::_Delegate<A,B...>* internalDelegate)
		{		
			this->internalDelegate = internalDelegate;
		}

		_event* add (__Internal__::_Delegate<A,B...>* other)
		{	
			if(internalDelegate != null)
			{
				internalDelegate = (__Internal__::_Delegate<A,B...>*)System::Delegate::Combine(internalDelegate, other);
			}
			else
			{
				internalDelegate = other;
			}
			return this;
		}
		
		_event* remove (__Internal__::_Delegate<A,B...>* other)
		{
			//TODO
			return this;
		}

		_event* operator += (__Internal__::_Delegate<A,B...>* other)
		{	
			return this->add(other);
		}
		
		_event* operator -= (__Internal__::_Delegate<A,B...>* other)
		{
			return this->remove(other);
		}

		operator _event*()
		{
			return this;
		}

	public:
		A fireEvent(B... args) 
		{
			if(internalDelegate != null)
			{
				return internalDelegate->Invoke(args...);
			}			
		}		
	};	
}
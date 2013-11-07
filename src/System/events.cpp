#pragma once
#include "events.h"

namespace __Internal__{

	void _event::setDelegate(System::Delegate internalDelegate)
	{
		this->internalDelegate = &internalDelegate;
	}

	_event& _event::operator += (const _event& other)
	{
		//TODO
		return *this;
	}
		
	_event& _event::operator -= (const _event& other)
	{
		//TODO
		return *this;
	}

	template<typename ... Arguments>
	void _event::fireEvent(Arguments... args) 
	{
		internalDelegate->Invoke(args...);
	}
}

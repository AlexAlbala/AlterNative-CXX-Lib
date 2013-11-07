#pragma once
#include "Delegate.h"

namespace __Internal__{	
	class _event
	{
	private:
		System::Delegate* internalDelegate;
		void setDelegate(System::Delegate internalDelegate);
		
	public:
		_event& operator += (const _event& other);
		_event& operator -= (const _event& other);
		
	protected:
		template<typename ... Arguments>
		void fireEvent(Arguments... args);
		
	};
}

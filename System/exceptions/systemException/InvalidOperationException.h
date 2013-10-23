#pragma once
#include "../SystemException.h"

namespace System{
	class String;
	
	class InvalidOperationException : public SystemException{
	public:
		InvalidOperationException();
		InvalidOperationException(String* message);
	};
}
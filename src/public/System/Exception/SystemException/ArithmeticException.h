#pragma once
#include "../SystemException.h"

namespace System{
	class String;
	class ArithmeticException : public SystemException{
	public:
		ArithmeticException();
		ArithmeticException(String* message);
	};
}

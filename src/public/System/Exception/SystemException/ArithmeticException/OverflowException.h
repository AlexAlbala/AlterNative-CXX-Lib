#pragma once
#include "../ArithmeticException.h"

namespace System{
	class String;
	class OverflowException : public ArithmeticException{
	public:
		OverflowException();
		OverflowException(String* message);
	};
}

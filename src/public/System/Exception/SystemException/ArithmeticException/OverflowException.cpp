#include "OverflowException.h"

namespace System{
	OverflowException::OverflowException() : ArithmeticException(new String("Number overflow.")) {
	}
	OverflowException::OverflowException(String* message) : ArithmeticException(message){
	}
}

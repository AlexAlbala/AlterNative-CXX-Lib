#include "ArithmeticException.h"

namespace System{
	ArithmeticException::ArithmeticException() : SystemException(new String("Overflow or underflow in the arithmetic operation.")) {
	}
	ArithmeticException::ArithmeticException(String* message) : SystemException(message){
	}
}

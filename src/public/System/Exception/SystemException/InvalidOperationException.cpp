#include "InvalidOperationException.h"

namespace System{
	InvalidOperationException::InvalidOperationException() : SystemException(){
	}
	InvalidOperationException::InvalidOperationException(String* message) : SystemException(message){
	}
}
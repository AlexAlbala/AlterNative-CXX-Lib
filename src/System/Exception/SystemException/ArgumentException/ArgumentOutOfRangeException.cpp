#include "ArgumentOutOfRangeException.h"

namespace System{
	ArgumentOutOfRangeException::ArgumentOutOfRangeException() : ArgumentException(){
	}

	ArgumentOutOfRangeException::ArgumentOutOfRangeException(String* message) : ArgumentException(message){
	}

	ArgumentOutOfRangeException::ArgumentOutOfRangeException(String* parameter, String* message) : ArgumentException(message){
	}
}
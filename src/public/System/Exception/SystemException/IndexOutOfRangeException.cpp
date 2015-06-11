#include "IndexOutOfRangeException.h"

namespace System{
	IndexOutOfRangeException::IndexOutOfRangeException() : SystemException(){
	}
	IndexOutOfRangeException::IndexOutOfRangeException(String* message) : SystemException(message){
	}
}
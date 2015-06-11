#include "NotSupportedException.h"

namespace System{
	NotSupportedException::NotSupportedException() : SystemException(){
	}
	NotSupportedException::NotSupportedException(String* message) : SystemException(message){
	}
}
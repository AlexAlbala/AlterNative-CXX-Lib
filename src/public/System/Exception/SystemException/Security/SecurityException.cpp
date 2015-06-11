#include "SecurityException.h"

namespace System{
	namespace IO{
		SecurityException::SecurityException() : SystemException(){
		}
		SecurityException::SecurityException(String* message) : SystemException(message){
		}
	}
}
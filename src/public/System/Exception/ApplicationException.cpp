#include "ApplicationException.h"

namespace System{
	ApplicationException::ApplicationException() : Exception() {	
	}
	ApplicationException::ApplicationException(String* message) : Exception(message){	
	}
}

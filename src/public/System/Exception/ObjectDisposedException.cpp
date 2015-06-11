#include "ObjectDisposedException.h"

namespace System{
	ObjectDisposedException::ObjectDisposedException() : Exception() {	
	}
	ObjectDisposedException::ObjectDisposedException(String* message) : Exception(message){	
	}
}

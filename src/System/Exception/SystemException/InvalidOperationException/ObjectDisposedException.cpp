#include "ObjectDisposedException.h"

namespace System{
	ObjectDisposedException::ObjectDisposedException() : InvalidOperationException(){
	}
	ObjectDisposedException::ObjectDisposedException(String* message) : InvalidOperationException(message){
	}
}
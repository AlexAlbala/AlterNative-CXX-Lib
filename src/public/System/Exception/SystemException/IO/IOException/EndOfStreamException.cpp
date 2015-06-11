#include "EndOfStreamException.h"

namespace System{
	namespace IO{
		EndOfStreamException::EndOfStreamException() : IOException(){
		}
		EndOfStreamException::EndOfStreamException(String* message) : IOException(message){
		}
	}
}
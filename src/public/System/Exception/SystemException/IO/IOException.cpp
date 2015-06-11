#include "IOException.h"

namespace System{
	namespace IO{
		IOException::IOException() : SystemException(){
		}
		IOException::IOException(String* message) : SystemException(message){
		}
	}
}
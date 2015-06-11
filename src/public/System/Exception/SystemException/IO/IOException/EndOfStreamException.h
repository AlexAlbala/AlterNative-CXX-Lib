#pragma once
#include "../IOException.h"

namespace System{	
	class String;
	namespace IO{
		
		class EndOfStreamException : public IOException{
		public:
			EndOfStreamException();
			EndOfStreamException(String* message);
		};
	}
}
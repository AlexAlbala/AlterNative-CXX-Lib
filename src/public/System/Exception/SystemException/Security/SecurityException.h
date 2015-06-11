#pragma once
#include "../../SystemException.h"

namespace System{	
	class String;
	namespace IO{
		
		class SecurityException : public SystemException{
		public:
			SecurityException();
			SecurityException(String* message);
		};
	}
}
#pragma once
#include "../../SystemException.h"

namespace System{	
	class String;
	namespace IO{
		
		class IOException : public SystemException{
		public:
			IOException();
			IOException(String* message);
		};
	}
}
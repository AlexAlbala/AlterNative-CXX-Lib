#pragma once
#include "../SystemException.h"

namespace System{
	class String;
	
	class IndexOutOfRangeException : public SystemException{
	public:
		IndexOutOfRangeException();
		IndexOutOfRangeException(String* message);
	};
}
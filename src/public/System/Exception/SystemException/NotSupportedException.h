#pragma once
#include "../SystemException.h"

namespace System{
	class String;
	class NotSupportedException : public SystemException{
	public:
		NotSupportedException();
		NotSupportedException(String* message);
	};
}
#pragma once
#include "../Exception.h"

namespace System{
	class String;
	class ApplicationException : public Exception{
	public:
		ApplicationException();
		ApplicationException(String* message);
	};
}
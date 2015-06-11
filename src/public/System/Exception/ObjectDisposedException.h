#pragma once
#include "../Exception.h"

namespace System{
	class String;
	class ObjectDisposedException : public Exception{
	public:
		ObjectDisposedException();
		ObjectDisposedException(String* message);
	};
}
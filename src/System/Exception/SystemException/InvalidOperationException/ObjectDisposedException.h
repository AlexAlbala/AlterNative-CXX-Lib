#pragma once
#include "../InvalidOperationException.h"

namespace System{
	class String;
	
	class ObjectDisposedException : public InvalidOperationException{
	public:
		ObjectDisposedException();
		ObjectDisposedException(String* message);
	};
}
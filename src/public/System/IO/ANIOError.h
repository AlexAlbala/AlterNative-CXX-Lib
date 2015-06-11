#pragma once
#include "../IDisposable.h"
namespace System{
	namespace IO{
		enum class ANIOError : int
		{
#ifndef _WINERROR_
			static int ERROR_SUCCESS = 0L;
#endif

		};
	}
}
#pragma once
#include <System/System.h>

namespace System {
	namespace Threading {
		struct NativeOverlapped : public ValueType
		{
			IntPtr EventHandle;
			IntPtr InternalHigh;
			IntPtr InternalLow;
			int OffsetHigh;
			int OffsetLow;			
		};	
	}
}
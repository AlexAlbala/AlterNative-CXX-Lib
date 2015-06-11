#pragma once
#include <System/Object.h>
#include <System/Runtime/InteropServices/SafeHandle.h>
using namespace System;
using namespace System::Runtime::InteropSevices;
namespace Microsoft{
	namespace Win32{
		namespace SafeHandles{
			class SafeHandleZeroOrMinusOneIsInvalid : public SafeHandle, public IDisposable {
			public:
				SafeHandleZeroOrMinusOneIsInvalid (bool ownsHandle) : SafeHandle ((IntPtr) 0, ownsHandle){}

				virtual bool getIsInvalid(){					
					return (*(handle.pointer) == (IntPtr)(-1)) || (*(handle.pointer) == (IntPtr)0);
				}
			};
		}
	}
}
#pragma once
#include <System/Object.h>
#include "SafeHandleZeroOrMinusOneIsInvalid.h"
#include <System/IO/ANIO.h>
#include <System/IO/ANIOError.h>
using namespace System;
using namespace System::IO;
namespace Microsoft{
	namespace Win32{
		namespace SafeHandles{
			class SafeFileHandle : public virtual SafeHandleZeroOrMinusOneIsInvalid{

				public:
				SafeFileHandle (IntPtr preexistingHandle, bool ownsHandle) : SafeHandleZeroOrMinusOneIsInvalid(ownsHandle)
				{
					SetHandle(preexistingHandle);
				}

				

				// This is just for marshalling
				/*internal SafeFileHandle () : base (true)
				{
				}*/

				protected:
				virtual bool ReleaseHandle ()
				{
					ANIOError error;
				
					ANIO::Close (handle, &error);

#ifdef _WINERROR_
					return ((int)error) == ERROR_SUCCESS
#else
					return error == ANIOError::ERROR_SUCCESS;
#endif
				}
			};
		}
	}
}
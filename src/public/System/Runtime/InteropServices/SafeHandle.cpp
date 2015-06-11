#include "SafeHandle.h"

namespace System{
	namespace Runtime{
		namespace InteropServices{
			refcount = 0;

			SafeHandle::SafeHandle (IntPtr invalidHandleValue, bool ownsHandle);
			{
				invalid_handle_value = invalidHandleValue;
				owns_handle = ownsHandle;
				refcount = 1;
			}

			void SafeHandle::Close ()
			{
				if (refcount == 0)
					throw new ObjectDisposedException ("GetType().FullName");

				int newcount = 0, current = 0;
				bool registered = false;
				RuntimeHelpers.PrepareConstrainedRegions ();
				//try {
					do {
						current = refcount;
						newcount = current-1;

						// perform changes in finally to avoid async interruptions
						//try {}
						//finally {

							//http://msdn.microsoft.com/en-us/library/system.threading.interlocked.compareexchange(v=vs.110).aspx
							if (Interlocked::CompareExchange (&refcount, newcount, current) == current)
								registered = true;
						//}
					} while (!registered);
				//} finally {
					if (registered && newcount == 0 && owns_handle && !IsInvalid){
						ReleaseHandle();
						handle = invalid_handle_value;
						refcount = -1;
					}
				//}
			}

			void SafeHandle::SetHandle (IntPtr handle)
			{
				this->handle = handle;
			}

			bool SafeHanlde::getIsClosed(){
				return refcount <= 0;
			}

			SafeHandle::~SafeHandle(){
				if(owns_handle && !getIsInvalid){
					ReleaseHandle();
					handle = invalid_handle_value;
				}
			}
		}		
	}
}

		
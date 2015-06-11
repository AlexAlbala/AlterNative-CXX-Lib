#pragma once
#include <System/System.h>

namespace System{
	namespace Runtime{
		namespace InteropSevices{
			class SafeHandle : public virtual IDisposable{

			private:
				IntPtr invalid_handle_value;
				int refcount;
				bool owns_handle;

			protected:
				IntPtr handle;
				SafeHandle (IntPtr invalidHandleValue, bool ownsHandle);
				virtual bool ReleaseHandle() = 0;

			public:
				virtual bool getIsInvalid() = 0;
				void SetHandle(IntPtr handle);
				bool getIsClosed();
				void Close();
				~SafeHandle();
			};
		}
	}
}
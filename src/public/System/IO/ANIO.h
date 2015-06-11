#pragma once
#include "../IDisposable.h"
#include "ANIOError.h"
namespace System{
	namespace IO{
		class ANIO
		{
		public:
			static void Close(IntPtr handle, ANIOError* error){
			}
		};
	}
}
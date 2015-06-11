#pragma once
#include "Stream.h"
namespace System{
	namespace IO{
		class MemoryStream : public Stream
		{
		public:
			void Dispose();
			virtual void Dispose(bool disposing);			
		};
	}
}
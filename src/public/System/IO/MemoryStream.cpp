#include "MemoryStream.h"

namespace System{
	namespace IO{
		void MemoryStream::Dispose(){
			this->Close();
		}

		void MemoryStream::Dispose(bool disposing){
		}		
	}
}
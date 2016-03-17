#pragma once
#include "../GC.h"
#include "../String.h"
#include "../Array.h"

namespace System{
	namespace Text{

		class StringBuilder : public virtual Object /*,ISerializable*/{

		private:
            stringstream ss;    
	
		public:
			int Length;
			StringBuilder();
			StringBuilder(int capacity);

			String* ToString();
            StringBuilder* Append(String* value);
			StringBuilder* Append(Array<char>* value , int startIndex, int charCount);
			StringBuilder* Append(char value);
		};
	}
}
#include "StringBuilder.h"

namespace System{
	namespace Text{
		StringBuilder::StringBuilder()
		{
			//DefaultCapacity = 16;
			//StringBuilder(DefaultCapacity);
		}

		StringBuilder::StringBuilder(int capacity)
		{
			//char* tmp = new char[capacity];
			//data = new String(tmp);
			//data->Length = capacity;
		}

		String* StringBuilder::ToString()
		{
			String* newstring = new String(ss.str().data());
            return newstring;
		}
        StringBuilder* StringBuilder::Append(String* value)
		{
            ss << value->data();
			return this;
		}

		StringBuilder* StringBuilder::Append(Array<char>* value , int startIndex, int charCount)
		{
			int i, end;
            for(i=startIndex,end=startIndex+charCount; i<end; i++) {
                ss << (*value)[i];
            }
			return this;
		}

		StringBuilder* StringBuilder::Append(char value)
		{
			ss << value;
			return this;
		}
	}
}
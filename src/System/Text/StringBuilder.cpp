#include "StringBuilder.h"

namespace System{
	namespace Text{
		StringBuilder::StringBuilder()
		{
			DefaultCapacity = 16;
			StringBuilder(DefaultCapacity);
		}

		StringBuilder::StringBuilder(int capacity)
		{
			char* tmp = new char[capacity];
			data = new String(tmp);
			data->Length = capacity;
		}

		String* StringBuilder::ToString()
		{
			return data;
		}

		StringBuilder* StringBuilder::Append(Array<char>* value , int startIndex, int charCount)
		{
			//TODO APPEND THE STRING TO DATA !!!!!!
			return this;
		}

		StringBuilder* StringBuilder::Append(char value)
		{
			//TODO APPEND THE STRING TO DATA !!!!!!
			return this;
		}
	}
}
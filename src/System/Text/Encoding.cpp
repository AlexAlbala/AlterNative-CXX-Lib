#include "Encoding.h"
#include "../String.h"
#include "../System.h"
#include <boost/locale.hpp>

namespace loc = boost::locale;

namespace System{
	namespace Text{

		Array<byte>* Encoding::UTF8::GetBytes(String* value){
			loc::generator gen;
			std::locale toLocale = gen("en_US.utf-8");			
			std::string converted = loc::conv::to_utf<char>(value->Data, toLocale);
			Array<char>* v = new Array<char>((char*)converted.data(),converted.size());
			return v;
		}

		String* Encoding::UTF8::GetString(byte* bytes){
			loc::generator gen;
			std::locale toLocale = gen("en_US.utf-8");

			std::string converted = loc::conv::from_utf(bytes,toLocale);
			return new String(converted.data());

		}

		String* Encoding::UTF8::GetString(Array<byte>* bytes)
		{        
			return GetString(bytes->GetData());
		}

		String* UTF8Encoding::GetString(Array<byte>* input)
		{
			return Encoding::UTF8::GetString(input->GetData());
		}

		Array<byte>* UTF8Encoding::GetBytes(String* input)
		{
			return Encoding::UTF8::GetBytes(input);
		}
	}
}
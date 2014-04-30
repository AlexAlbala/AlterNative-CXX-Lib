#pragma once
#include "../System.h"

namespace System{
	namespace Text{
		class Encoding : public Object{
			public : 
				class UTF8
				{
				public:
					static Array<char>* GetBytes(String* value);
					static String* GetString(char* bytes);
					static String* GetString(Array<char>* bytes);
				};

		};

		class UTF8Encoding : public Object{
		public:
			String* GetString(Array<char>* input);
			Array<char>* GetBytes(String* input);
		};
	}
}

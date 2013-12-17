#pragma once
#include <string.h>
#include "Object.h"
#include "GC.h"
#include "support.h"
#include "Array.h"

namespace System{
	class String : public Object {
	public:
		int Length;
		char* Data;
		String(void);
		String(int txt);
		String(long txt);
		String(char txt);
		String(const char* txt);
		String(Array<char>* txt);
		String* operator =(char* text);
		Array<char>* ToCharArray();
		operator const char*();
		virtual ~String(void);
		String* ToString(void);
		String* ToLower();
		String* ToUpper();
		static String* Concat(Array<String>* elements);
		static String* Concat(Array<Object>* elements);

	};
}

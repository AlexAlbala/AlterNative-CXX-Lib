#pragma once
#include <string.h>
#include "Object.h"
#include "GC.h"
#include "support.h"
#include "Array.h"

namespace System{
	class String : public std::string, public Object {

	private:
		//char* Data;
		//int Length;
	public:		
		String(void);
		String(int txt);
		String(long txt);
		String(char txt);
		String(float txt);
		String(const char* txt);
		String(Array<char>* txt);
		~String(void);
		String* operator =(char* text);
		Array<char>* ToCharArray();
		operator const char*();
		operator char*();		
		String* ToString(void);
		String* ToLower();
		String* ToUpper();
		
		int IndexOf(const char c);
		static String* Concat(Array<String>* elements);
		static String* Concat(Array<Object>* elements);

		inline String* Substring(int pos){
			return new String(std::string::substr(pos).data());
		}
	
		inline String* Substring(int pos, int length){
			return new String(std::string::substr(pos, length).data());
		}

		inline int getLength(){
			return std::string::length();
		}

	};
}

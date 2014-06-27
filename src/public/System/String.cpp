#include "Object.h"
#include "String.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

namespace System{	

	String::String() : std::string() {		
	}

	String::String(int val) : std::string(::an_itoca(val)) {	
		
	}

	String::String(long val) : std::string(::an_ltoca(val)) {			
	}

	String::String(char txt) : std::string(::an_ctoca(txt)) {		
	}

	String::String(float txt) : std::string(::an_ftoca(txt)) {		
	}

	String::String(const char* txt) : std::string((const char*)txt){		
	}

	String::String(Array<char>* txt) {
		char* tmp = *txt;
		std::string((const char*)tmp);	
	}

	String::operator const char*()
	{
		return std::string::data();
	}

	String::operator char*()
	{
		return (char*)std::string::data();
	}

	String::~String(){		
	}	


	Array<char>* String::ToCharArray()	{
		return new Array<char>((char*)std::string::data(), std::string::length());
	}

	String* String::operator=(char* text) {
		return new String(text);
	}

	
	String* String::Concat(Array<String>* elements) {		
		stringstream ss;
		for(int i = 0; i < elements->Length; i++)
		{
			String* s = (*elements)[i];
			ss << s->data();			
		}
		
		String* newstring = new String(ss.str().data());
		//delete elements;
		return newstring;
	}

	String* String::Concat(Array<Object>* elements) {		
		Array<String>* stringArray = new Array<String>(elements->Length);

		for(int i = 0; i < elements->Length; i++)
		{
			Object* tmp = (*elements)[i];
			String* tmp_s;

			if(is_inst_of<String*>(tmp))
			{
				tmp_s = as_cast<String*>(tmp);
			}
			else
			{
				tmp_s = tmp->ToString();	
			}
			stringArray->SetData(i, tmp_s);
		}		
		return Concat(stringArray);
	}

	String* String::ToLower()
	{
		String* resString = new String(stolower((char*)std::string::data()));
		return resString;
	}

	String* String::ToUpper()
	{		
		String* resString = new String(stoupper((char*)std::string::data()));
		return resString;
	}	

	int String::IndexOf(const char c)
	{		
		size_t index = std::string::find(c, 0);
		if(index != std::string::npos)
			return index;
		else
			return -1;
	}

	/*
	inlined method
	int String::getLength()
	{
		return std::string::length();
	}
	*/

	String* String::ToString()
	{
		return this;
	}
}
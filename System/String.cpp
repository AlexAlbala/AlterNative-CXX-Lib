#include "String.h"
#include <stdlib.h>
#include <stdio.h>

namespace System{

	String::String() {
		Data = new char[0];
		Length = 0;
	}

	String::String(int val) {	
		char* tmp = new char[33];
		sprintf(tmp, "%d", val);
		Length = strlen(tmp);
		Data = new char[Length];
		memcpy(Data, tmp, Length);
		delete tmp;
	}

	String::String(long val) {	
		char* tmp = new char[66];
		sprintf(tmp, "%d", val);
		Length = strlen(tmp);
		Data = new char[Length];
		memcpy(Data, tmp, Length);
		delete tmp;
	}

	String::String(char txt) {
	
		Length = 1;
		Data = new char[1];
		Data[0] = txt;
	}

	String::String(const char* txt) {
		//TODO It will be nice to not to copy "constant" strings 
		Length = strlen(txt);
		Data = new char[Length+1];
		strncpy(Data,txt,Length);
	}

	Array<char>* String::ToCharArray()
	{
		return new Array<char>(Data, Length);
	}

	String* String::operator=(char* text) {
		String* s = new String(text);
		return s;
	}

	String::operator const char*()
	{
		return Data;
	}

	String::~String() {
		if(Data!=null) {
			delete Data;
			Data = null;
		}
	}
	
	String* String::Concat(Array<String>* elements) {
		String* newstring = new String();
		for(int i = 0; i < elements->Length; i++)
		{
			String* s = (*elements)[i];
			int len = s->Length;
			memcpy(newstring->Data+newstring->Length,s->Data,s->Length);
			newstring->Length += s->Length;
		}                
		delete elements;
		return newstring;
	}

	String* String::Concat(Array<Object>* elements) {
		String* newstring = new String();
		for(int i = 0; i < elements->Length; i++)
		{
			String* s = (*elements)[i]->ToString();
			int len = s->Length;
			memcpy(newstring->Data + newstring->Length, s->Data, s->Length);
			newstring->Length += s->Length;
		}                
		delete elements;
		return newstring;
	}	
		
	String* String::ToString()
	{
		return this;
	}
}
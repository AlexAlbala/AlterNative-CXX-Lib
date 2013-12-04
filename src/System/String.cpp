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

	String::String(Array<char>* txt) {
		Length = txt->Length;
		Data = *txt;
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

		int totalLength = 0;
		for(int i = 0; i < elements->Length; i++)
		{
			totalLength += (*elements)[i]->Length;
		}
		newstring->Data = new char[totalLength];

		for(int i = 0; i < elements->Length; i++)
		{
			String* s = (*elements)[i];
			//strncpy(newstring->Data + newstring->Length, s->Data, s->Length);
			memcpy(newstring->Data + newstring->Length, s->Data, s->Length);
			newstring->Length += s->Length;
			delete s;
		}                
		delete elements;
		return newstring;
	}

	String* String::Concat(Array<Object>* elements) {
		Array<String>* stringArray = new Array<String>(elements->Length);

		for(int i = 0; i < elements->Length; i++)
		{
			stringArray->SetData(i , (String*)(*elements)[i]);
		}
		delete elements;
		return Concat(stringArray);
	}	
		
	String* String::ToString()
	{
		return this;
	}
}
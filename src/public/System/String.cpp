#include "Object.h"
#include "String.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/regex.hpp>

namespace System{	
	String* String::Empty = new String("");

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

	String* String::ToString()
	{
		return this;
	}

	long int String::GetHashCode()
	{
		const char* chPtr = this->data();
		int num = 352654597;
		int num2 = num;
		int* numPtr = (int*)chPtr;
		int length = this->getLength();
		for (int i = length; i > 0; i -= 4)
		{
			num = (((num << 5) + num) + (num >> 27)) ^ numPtr[0];
			if (i <= 2)			
				break;

			num2 = (((num2 << 5) + num2) + (num2 >> 27)) ^ numPtr[1];
			numPtr += 2;
		}
		return (num + (num2 * 1566083941));
	}

	Array<String>* String::Split(Array<char>* delim)
	{
		std::string s = *this;		
		std::string delimiter = delim != null ? *delim : " ";
				
		if(delimiter.size() == 0)
			delimiter = " ";

		std::vector<std::string> res;

		size_t pos = 0, count=0;
		std::string token;
		while ((pos = s.find(delimiter)) != std::string::npos) {
			token = s.substr(0, pos);
			res.push_back(token);
			s.erase(0, pos + delimiter.length());
		}
		res.push_back(s);	
		
		Array<String>* result = new Array<String>(res.size());
		for(int i = 0; i <res.size(); i++)
			result->SetData(i, new String(res.at(i).data()));

		return result;
	}
}
#pragma once
#include "Object.h"
#include "String.h"
#include <exception>

using namespace std;
namespace System{
	class Exception : public Object, public exception{

	private:
		Exception* inner;
	public:
		Exception();
		Exception(String* message);	
		Exception(String* message, Exception* inner);
		~Exception() throw();
		String* Message;
	};
}
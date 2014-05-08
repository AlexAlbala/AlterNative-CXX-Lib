#include "Exception.h"

namespace System{
	Exception::Exception(){
		std::exception();
		Message = new String("");
		this->inner = null;
	}
	
	Exception::Exception(String* message){
		std::exception();
		this->Message = message;
		this->inner = null;
	}

	Exception::Exception(String* message, Exception* inner){
		std::exception();
		this->Message = message;
		this->inner = inner;
	}
	
	Exception::~Exception() throw(){
		this->Message = null;
		this->inner = null;
	}
}
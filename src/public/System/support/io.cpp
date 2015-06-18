#include "io.h"
namespace __Internal__{
	boost::asio::io_service* __ioserv = 0;	
}

namespace AN_GLOBALS {
	boost::asio::io_service* io_service(){
		if(::__Internal__::__ioserv == 0){
			::__Internal__::__ioserv = new boost::asio::io_service();
		}
		return ::__Internal__::__ioserv;
	}
}
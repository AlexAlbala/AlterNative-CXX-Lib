#pragma once
#include <boost/asio.hpp>

/*********************************************************************************************************/
/************************************************* IO  ***************************************************/
/*********************************************************************************************************/
namespace __Internal__{
	boost::asio::io_service* __ioserv = null;
}

#define AN_MAX_BUFFER_LENGTH 1024*1024 //Maximum size of sockets buffer (default 1MB)

namespace AN_GLOBALS {
	boost::asio::io_service* io_service(){
		if(::__Internal__::__ioserv == null){
			::__Internal__::__ioserv = new boost::asio::io_service();
		}
		return ::__Internal__::__ioserv;
	}
}
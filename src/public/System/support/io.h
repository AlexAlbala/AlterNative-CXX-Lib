#pragma once
#include <boost/asio.hpp>

/*********************************************************************************************************/
/************************************************* IO  ***************************************************/
/*********************************************************************************************************/


namespace __Internal__{
	extern boost::asio::io_service* __ioserv;
}

namespace AN_GLOBALS {
	boost::asio::io_service* io_service();
}

#define AN_MAX_BUFFER_LENGTH 1024*1024 //Maximum size of sockets buffer (default 1MB)
#pragma once
#include <System/System.h>
#include "Sockets/AddressFamily.h"
#include <System/Exception/SystemException/ArgumentException/ArgumentOutOfRangeException.h>
#include <System/Exception/SystemException/ArgumentException/ArgumentNullException.h>
#include <System/Exception/SystemException/ArgumentException.h>
#include "IPAddress.h"
#include "EndPoint.h"


using namespace System;
using namespace System::Net::Sockets;
namespace System {
	namespace Net {
		//Attribute: Serializable*
		class IPEndPoint : public EndPoint, public virtual Object{
		private:
			IPAddress* m_Address;
		private:
			int m_Port;
		public:
			static IPEndPoint* Any;			
		public:
			virtual AddressFamily getAddressFamily();
			//Ignored empty method declaration
		public:
			IPAddress* getAddress();
		public:
			void setAddress(IPAddress* value);
		public:
			int getPort();
		public:
			void setPort(int value);
		public:
			IPEndPoint(long address, int port);
		public:
			IPEndPoint(IPAddress* address, int port);
		public:
			String* ToString();
		};
	}
}
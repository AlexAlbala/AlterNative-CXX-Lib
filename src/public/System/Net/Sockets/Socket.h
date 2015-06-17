#pragma once
#include <System/System.h>
#include "AddressFamily.h"
#include "ProtocolType.h"
#include "SocketType.h"
#include "PracticalSocket.h"
#include "../IPEndPoint.h"
#include "../EndPoint.h"
#include "../IPAddress.h"

using namespace System::Net;
namespace System{
	namespace Net{
		namespace Sockets{
			class Socket : public virtual Object {
			public:
				Socket(AddressFamily addressFamily, SocketType socketType, ProtocolType protocolType);
				int Send(Array<char>* data);
				void Close();
				void Connect(EndPoint* endPoint);
				void Connect(IPAddress* ipAddress, int port);

			private:			
				CommunicatingSocket* _socket;
				AddressFamily _family;

			};
		}
	}
}
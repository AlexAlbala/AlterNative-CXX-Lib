#pragma once
#include <System/System.h>
#include "AddressFamily.h"
#include "ProtocolType.h"
#include "SocketType.h"
#include "PracticalSocket.h"
#include "../IPEndPoint.h"
#include "../EndPoint.h"
#include "../IPAddress.h"
#include "SocketFlags.h"

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
				Socket* Accept();
				int Receive(Array<char>* buffer);
				int Receive(Array<char>* buffer, int length, SocketFlags socketFlags);
				int Receive(Array<char>* buffer, int length, int offset, SocketFlags socketFlags);

				void Listen(int backLog);
				void Bind(EndPoint* endPoint);

			private:			
				CommunicatingSocket* _socket;
				TCPServerSocket* _tcpsrvsocket;
				AddressFamily _family;
				ProtocolType _protocol;
				EndPoint* _binding;
			};
		}
	}
}
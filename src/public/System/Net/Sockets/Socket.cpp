#include "Socket.h"

namespace System{
	namespace Net{
		namespace Sockets{
			Socket::Socket(AddressFamily addressFamily, SocketType socketType, ProtocolType protocolType){
				this->_family = addressFamily;
				switch(protocolType){
				case ProtocolType::Udp:
					_socket = new UDPSocket();
					break;
				case ProtocolType::Tcp:
					_socket = new TCPSocket();
					break;
				default:
					_socket = null;
					throw new System::Exception(new String("KE ASE"));
				}
			}

			void Socket::Connect(EndPoint* endPoint){
				if(this->_family == AddressFamily::InterNetwork){
					IPEndPoint* ipep = (IPEndPoint*)endPoint;
					this->Connect(ipep->getAddress(), ipep->getPort());
				}
			}

			void Socket::Connect(IPAddress* ipAddress, int port){
					_socket->connect(*(ipAddress->ToString()), port);
			}

			int Socket::Send(Array<char>* data){
				_socket->send(*data, data->Length);
				return data->Length;
			}

			void Socket::Close(){				
				delete _socket;
				_socket = null;
			}
		}
	}
}
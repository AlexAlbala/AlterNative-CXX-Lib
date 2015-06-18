#include "Socket.h"

namespace System{
	namespace Net{
		namespace Sockets{
			Socket::Socket(AddressFamily addressFamily, SocketType socketType, ProtocolType protocolType){
				this->_family = addressFamily;
				this->_protocol = protocolType;
				switch(protocolType){
				case ProtocolType::Udp:
					_socket = new UDPSocket();
					break;
				case ProtocolType::Tcp:
					_socket = new TCPSocket();
					break;
				default:
					_socket = null;
					throw new System::Exception(new String("Invalid protocol type"));
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

			void Socket::Listen(int backLog){
				if(this->_family == AddressFamily::InterNetwork){
					assert(_binding != null);
					IPEndPoint* ipep = (IPEndPoint*)_binding;
					if(this->_protocol == ProtocolType::Tcp){	
						_tcpsrvsocket = new TCPServerSocket(*(ipep->getAddress()->ToString()), ipep->getPort(), backLog);
					}
				}
			}

			void Socket::Bind(EndPoint* endPoint){
				this->_binding = endPoint;				
			}

			int Socket::Send(Array<char>* data){
				_socket->send(*data, data->Length);
				return data->Length;
			}

			void Socket::Close(){				
				if(_tcpsrvsocket != null){
					_tcpsrvsocket->cleanUp();
					delete _tcpsrvsocket;
				}

				if(_socket != null){
					_socket->cleanUp();
					delete _socket;
				}

				_socket = null;
				_tcpsrvsocket = null;
			}

			Socket* Socket::Accept(){
				if(this->_protocol == ProtocolType::Tcp){					
					return (Socket*)_tcpsrvsocket->accept();
				}
				return null;
			}

			int Socket::Receive(Array<char>* buffer){
				return Receive(buffer, AN_MAX_BUFFER_LENGTH, SocketFlags::None);
			}

			int Socket::Receive(Array<char>* buffer, int length, SocketFlags socketFlags){
				return this->Receive(buffer, length, 0, socketFlags);
			}

			int Socket::Receive(Array<char>* buffer, int length, int offset, SocketFlags socketFlags){
				return _socket->recv(*buffer + offset, length);
			}
		}
	}
}
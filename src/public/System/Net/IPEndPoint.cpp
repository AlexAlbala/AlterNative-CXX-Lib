#include "IPEndPoint.h"
namespace System {
	namespace Net {
		//IPEndPoint* IPEndPoint::Any = new IPEndPoint(IPAddress::Any, 0);
		//IPEndPoint* IPEndPoint::IPv6Any = new IPEndPoint(IPAddress::IPv6Any, 0);

		AddressFamily IPEndPoint::getAddressFamily(){
			return this->m_Address->getAddressFamily();
		}
		IPAddress* IPEndPoint::getAddress()
		{
			return this->m_Address;
		}
		void IPEndPoint::setAddress(IPAddress* value)
		{
			this->m_Address = value;
		}
		int IPEndPoint::getPort()
		{
			return this->m_Port;
		}
		void IPEndPoint::setPort(int value)
		{
			/*if (!ValidationHelper::ValidateTcpPort(value)) {
				throw new ArgumentOutOfRangeException(new String("value"));
			}*/

			if (value < 1 || value >= 65535) {
				throw new ArgumentOutOfRangeException(new String("value"));
			}

			this->m_Port = value;
		}
		IPEndPoint::IPEndPoint(long address, int port)
		{
			/*AnyPort = 0;
			MaxPort = 65535;
			MinPort = 0;
			if (!ValidationHelper::ValidateTcpPort(port)) {
				throw new ArgumentOutOfRangeException(new String("port"));
			}*/

			this->m_Port = port;
			this->m_Address = new IPAddress(address);
		}
		IPEndPoint::IPEndPoint(IPAddress* address, int port)
		{
			if (address == null) {
				throw new ArgumentNullException(new String("address"));
			}
			/*if (!ValidationHelper::ValidateTcpPort(port)) {
				throw new ArgumentOutOfRangeException(new String("port"));
			}*/
			if (port < 1 || port >= 65535) {
				throw new ArgumentOutOfRangeException(new String("value"));
			}
			this->m_Port = port;
			this->m_Address = address;
		}

		String* IPEndPoint::ToString(){
			Array<String>* str = new Array<String>(3);
			str->SetData(0, this->m_Address->ToString());
			str->SetData(1, new String(":"));
			str->SetData(2, new String(this->m_Port));
			return String::Concat(str);
		}
	}
}
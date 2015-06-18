#include "IPAddress.h"
#include <System/Exception/SystemException/ArgumentException/ArgumentOutOfRangeException.h>
namespace System {
	namespace Net {
		/*static IPAddress* IPAddress::Any = new IPAddress(0);
		static IPAddress* IPAddress::Loopback = new IPAddress(16777343);
		static IPAddress* IPAddress::Broadcast = new IPAddress((long)((ulong)(-1)));
		static IPAddress* IPAddress::None = IPAddress::Broadcast;*/

		//IPAddress* IPAddress::IPv6Any;
		//IPAddress* IPAddress::IPv6Loopback;
		//IPAddress* IPAddress::IPv6None;
		long IPAddress::getAddress(){			
			return this->m_Address;
		}
		void IPAddress::setAddress(long value)
		{			
			if (this->m_Address != value) {
				this->m_ToString = null;
				this->m_Address = value;
			}
		}
		AddressFamily IPAddress::getAddressFamily()
		{
			return this->m_Family;
		}


		IPAddress::IPAddress(long newAddress)
		{
			m_Numbers = new Array<ushort>(8);
			m_Family = AddressFamily::InterNetwork;

			/*NumberOfLabels = 8;
			IPv6AddressBytes = 16;
			IPv4AddressBytes = 4;
			LoopbackMask = 255L;*/

			if (newAddress < 0L || newAddress > (long)((ulong)(-1))) {
				throw new ArgumentOutOfRangeException(new String("newAddress"));
			}
			this->m_Address = newAddress;

			this->m_ToString = null;
		}
		IPAddress::IPAddress(Array<ushort>* address)
		{
			if (address == null) {
				throw new ArgumentNullException(new String("address"));
			}
			if (address->Length != 4 && address->Length != 16) {
				throw new ArgumentException(new String("address"));
			}
			if (address->Length == 4) {
				this->m_Family = AddressFamily::InterNetwork;
				this->m_Address = (long int)((int)((*address)[3]) << 24 | (int)((*address)[2]) << 16 | (int)((*address)[1]) << 8 | (int)((*address)[0]));// & (-1 << 24);
				return;
			}
			this->m_Family = AddressFamily::InterNetworkV6;
			for (int i = 0; i < 8; i += 1) {
				this->m_Numbers->SetData(i, (ushort)((int)((*address)[i * 2]) * 256 + (int)((*address)[i * 2 + 1])));
			}

			this->m_ToString = null;
		}
		IPAddress::IPAddress(int newAddress)
		{
			this->m_Address = (long)(newAddress) & (long)((ulong)(-1));
			this->m_ToString = null;
		}

		Array<char>* IPAddress::GetAddressBytes()
		{ 
			Array<char>* array;
			if (this->m_Family == AddressFamily::InterNetworkV6) {
				array = new Array<char>(16);
				int num = 0;
				for (int i = 0; i < 8; i += 1) {
					array->SetData(num++, (char)((*this->m_Numbers)[i] >> 8 & 255));
					array->SetData(num++, (char)((*this->m_Numbers)[i] & 255));
				}
			}
			else {
				array = new Array<char>(4);
				array->SetData(0, (char)(this->m_Address));
				array->SetData(1, (char)(this->m_Address >> 8));
				array->SetData(2, (char)(this->m_Address >> 16));
				array->SetData(3, (char)(this->m_Address >> 24));
			}
			return array;
		}		

		IPAddress::IPAddress(Array<ushort>* address, uint scopeid)
		{
			this->m_Family = AddressFamily::InterNetworkV6;
			this->m_Numbers = address;
			this->m_ScopeId = (long)((ulong)(scopeid));
			this->m_ToString = null;
		}
		IPAddress::IPAddress()
		{
			this->m_ToString = null;
			//ONLY IPV6
			/*Array<char>* address = new Array<char>(16);
			IPAddress::IPv6Any = new IPAddress(address, 0L);
			Array<char>* array = new Array<char>(16);
			array->SetData(15, 1);
			IPAddress::IPv6Loopback = new IPAddress(array, 0L);
			Array<char>* address2 = new Array<char>(16);
			IPAddress::IPv6None = new IPAddress(address2, 0L);*/
		}

		IPAddress* IPAddress::Parse(String* ipString){

			Array<String>* splitted = ipString->Split(new String("."));

			Array<ushort>* address = new Array<ushort>(4);

			ushort c0 = (ushort)stoi(*(splitted->GetData(0)));
			ushort c1 = (ushort)stoi(*(splitted->GetData(1)));
			ushort c2 = (ushort)stoi(*(splitted->GetData(2)));
			ushort c3 = (ushort)stoi(*(splitted->GetData(3)));

			//std::cout << std::endl << "chars" << (ushort)c0 << std::endl << (ushort) c1 << std::endl << (ushort)c2 << std::endl << (ushort)c3 << std::endl;

			//std::cout << std::endl << "strings" << splitted->GetData(0)->c_str() << std::endl << splitted->GetData(1)->c_str() << std::endl << splitted->GetData(2)->c_str() << std::endl << splitted->GetData(3)->c_str() << std::endl;

			address->SetData(0, c0);
			address->SetData(1, c1);
			address->SetData(2, c2);
			address->SetData(3, c3);

			return new IPAddress(address);
		}

		String* IPAddress::ToString(){
			if(this->m_ToString == null){
				int num2 = 15;
				char* ptr = new char[15];

				int num3 = (int)((this->m_Address >> 24) & 255L);
				do {
					ptr[(num2 -= 1)] = (char)(48 + (num3 % 10));
					num3 /= 10;
				}
				while (num3 > 0);
				ptr[(num2 -= 1)]  = '.';
				num3 = (int)((this->m_Address >> 16) & 255L);
				do {
					ptr[(num2 -= 1)] = (char)(48 + (num3 % 10));
					num3 /= 10;
				}
				while (num3 > 0);
				ptr[(num2 -= 1)] = '.';
				num3 = (int)((this->m_Address >> 8) & 255L);
				do {
					ptr[(num2 -= 1)] = (char)(48 + (num3 % 10));
					num3 /= 10;
				}
				while (num3 > 0);
				ptr[(num2 -= 1)] = '.';
				num3 = (int)(this->m_Address & 255L);
				do {
					ptr[(num2 -= 1)] = (char)(48 + (num3 % 10));
					num3 /= 10;
				}
				while (num3 > 0);


				char* str = new char[15];
				memcpy(str, ptr + num2, 15-num2); 
				this->m_ToString = new String(str);
			}
			return this->m_ToString;
		}
	}
}
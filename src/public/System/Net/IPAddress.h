#pragma once
#include <System/System.h>
#include "Sockets/AddressFamily.h"
#include <System/Exception/SystemException/ArgumentException/ArgumentNullException.h>
#include <System/Text/StringBuilder.h>

using namespace System;
using namespace System::Net::Sockets;
using namespace System::Text;
namespace System {
	namespace Net {
		class IPAddress : public virtual Object{
		private:
			AddressFamily m_Family;
			Array<ushort>* m_Numbers;
			String* m_ToString;
			long m_ScopeId;

		public:
			/*static IPAddress* Any;
			static IPAddress* Loopback;
			static IPAddress* Broadcast;
			static IPAddress* None;*/

			long m_Address;
			long getAddress();
			void setAddress(long value);
			AddressFamily getAddressFamily();
			Array<char>* GetAddressBytes();

			static IPAddress* Parse(String* ipString);
			//static IPAddress* InternalParse(String* ipString, bool tryParse);
			//bool TryParse(String* ipSstring, IPAddress* address);
			IPAddress(long newAddress);
			IPAddress(Array<ushort>* address);
			IPAddress(Array<ushort>* address, uint scopeId);
			IPAddress();
			IPAddress(int address);
			String* ToString();
		};	
	}
}
#pragma once
namespace System {
	namespace Net {
		namespace Sockets {
			enum class SocketType{
				Stream = 1,
				Dgram,
				Raw,
				Rdm,
				Seqpacket,
				Unknown = -1
			};
		}
	}
}
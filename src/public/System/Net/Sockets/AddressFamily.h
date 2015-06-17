#pragma once
namespace System {
	namespace Net {
		namespace Sockets {
			enum class AddressFamily{
				Unknown = -1,
				Unspecified,
				Unix,
				InterNetwork,
				ImpLink,
				Pup,
				Chaos,
				NS,
				Ipx = 6,
				Iso,
				Osi = 7,
				Ecma,
				DataKit,
				Ccitt,
				Sna,
				DecNet,
				DataLink,
				Lat,
				HyperChannel,
				AppleTalk,
				NetBios,
				VoiceView,
				FireFox,
				Banyan = 21,
				Atm,
				InterNetworkV6,
				Cluster,
				Ieee12844,
				Irda,
				NetworkDesigners = 28,
				Max
			};
		}
	}
}
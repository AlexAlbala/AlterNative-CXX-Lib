#pragma once
#include <System/System.h>

using namespace System;
namespace System {
	namespace Security {
		namespace Permissions {
			enum class FileIOPermissionAccess{
				NoAccess = 0,
				Read = 1,
				Write = 2,
				Append = 4,
				PathDiscovery = 8,
				AllAccess = 15
			};
		}
	}
}
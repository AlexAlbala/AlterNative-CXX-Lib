#pragma once
#include <System/System.h>

using namespace System;
namespace System {
	namespace Security {
		namespace AccessControl {
			//Attribute: Flags*
			enum class AccessControlSections{
				None = 0,
				Audit = 1,
				Access = 2,
				Owner = 4,
				Group = 8,
				All = 15
			};
		}
	}
}
#pragma once
#include <System/System.h>

using namespace System;
namespace System {
	namespace Security {
		namespace AccessControl {
			//Attribute: Flags*
			enum class AccessControlActions{
				None = 0,
				View = 1,
				Change = 2
			};
		}
	}
}
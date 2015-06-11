#pragma once
#include <System/System.h>

using namespace System::Runtime::InteropServices;
namespace System {
	//Attribute: __DynamicallyInvokable*
	//Attribute: ComVisible*(true)
	//Attribute: Serializable*
	enum class StringComparison{
		CurrentCulture,
		CurrentCultureIgnoreCase,
		InvariantCulture,
		InvariantCultureIgnoreCase,
		Ordinal,
		OrdinalIgnoreCase
	};
}
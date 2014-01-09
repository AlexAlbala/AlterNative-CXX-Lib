#pragma once

namespace System {
	namespace Threading {
		enum class StackCrawlMark
		{
			LookForMe,
			LookForMyCaller,
			LookForMyCallersCaller,
			LookForThread
		};	
	}
}
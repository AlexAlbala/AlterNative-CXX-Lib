#pragma once
#include <System/System.h>

using namespace System;
namespace System {
	namespace Security {
		namespace AccessControl {
			enum class FileSystemRights{
				ReadData = 1,
				ListDirectory = 1,
				WriteData = 2,
				CreateFiles = 2,
				AppendData = 4,
				CreateDirectories = 4,
				ReadExtendedAttributes = 8,
				WriteExtendedAttributes = 16,
				ExecuteFile = 32,
				Traverse = 32,
				DeleteSubdirectoriesAndFiles = 64,
				ReadAttributes = 128,
				WriteAttributes = 256,
				Delete = 65536,
				ReadPermissions = 131072,
				ChangePermissions = 262144,
				TakeOwnership = 524288,
				Synchronize = 1048576,
				FullControl = 2032127,
				Read = 131209,
				ReadAndExecute = 131241,
				Write = 278,
				Modify = 197055
			};
		}
	}
}
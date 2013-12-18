#include "File.h"
#include "FileMode.h"
#include "FileAccess.h"
#include <boost/filesystem.hpp>

namespace System{
	namespace IO{
		bool File::Exists(String* path)
		{
			const char* _path = *path;
			return boost::filesystem::exists(_path); 
		}

		void File::Delete(String* path)
		{
			remove(*path);
		}

		FileStream* File::Create(String* path)
		{
			return new FileStream(path, FileMode::CreateNew, FileAccess::ReadWrite);
		}

		FileStream* File::OpenRead(String* path)
		{
			if(File::Exists(path))
			{
				return new FileStream(path, FileMode::Open, FileAccess::Read);
			}
			else
				throw std::exception();//TODO: FILENOTFOUNDEXCEPTION
		}

		String* File::ReadAllText(String* path)
		{
			if (path == null)
			{
				throw new ArgumentNullException(new String("path"));
			}
			if (path->Length == 0)
			{
				// While we don't have the Environment class
				//throw new ArgumentException(Environment.GetResourceString("Argument_EmptyPath"));
				throw new ArgumentException(new String("Argument_EmptyPath"));
			}
			/*return File.InternalReadAllText(path, Encoding.UTF8, true);*/
			return File::InternalReadAllText(path,  true);
		}

		void File::WriteAllText(String* path, String* contents)
		{
			if (path == null)
			{
				throw new ArgumentNullException(new String("path"));
			}
			if (path->Length == 0)
			{
				// While we don't have the Environment class
				//throw new ArgumentException(Environment.GetResourceString("Argument_EmptyPath"));
				throw new ArgumentException(new String("Argument_EmptyPath"));
			}
			File::InternalWriteAllText(path, contents, true);
		}

		/*String* InternalReadAllText(String* path, Encoding encoding, bool checkHost)*/
		String* File::InternalReadAllText(String* path, bool checkHost)
		{
			String* result;
			StreamReader* streamReader = new StreamReader(path);
			result = streamReader->ReadToEnd();
			return result;
		}

		void File::InternalWriteAllText(String* path, String* contents, bool checkHost)
		{
			StreamWriter* streamWriter = new StreamWriter(path);
			streamWriter->Write(contents);
			streamWriter->Flush();
			streamWriter->Close();
		}
	}
}

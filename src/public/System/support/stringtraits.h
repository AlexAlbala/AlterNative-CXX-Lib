#pragma once

namespace{
	char* stoupper( char* s )
	{
		char* p = s;
		while (*p = toupper( *p )) p++;
		return s;
	}	

	char* stolower( char* s )
	{
		char* p = s;
		while (*p = tolower( *p )) p++;
		return s;
	}

	const char* an_ctoca(char txt)
	{		
		char* tmp = new char[1];
		tmp[0] = txt;
		return tmp;
	}

	inline const char* an_itoca(int val)
	{
		char* tmp = new char[33];
#ifdef _MSC_VER
		//::itoa(val, tmp, 10);
		::_itoa_s(val, tmp, 33, 10);
#else
		sprintf(tmp, "%d", val);
#endif
		return tmp;
	}

	inline const char* an_ltoca(long long val)
	{	
		char* tmp = new char[66];
//#ifdef _MSC_VER
		//::_ltoa_s(val, tmp, 33, 10);		
//#else
		sprintf_s(tmp, 66, "%lld", val);
//#endif
		return tmp;
	}

	inline const char* an_ftoca(float val)
	{	
		char* tmp = new char[66];
		sprintf_s(tmp, 66, "%f", val);
//		sprintf_s(tmp, "%f", val);
		return tmp;
	}
}

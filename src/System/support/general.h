#pragma once

/*********************************************************************************************************/
/*********************************************** GENERAL  ************************************************/
/*********************************************************************************************************/
#define null								(0)
#define byte								char

#ifndef __linux__
	#ifndef __APPLE__
		#define uint							unsigned int
		#define ushort							unsigned short
	#endif
	#define ulong								unsigned long long
#endif





#pragma once

/*********************************************************************************************************/
/*********************************************** GENERAL  ************************************************/
/*********************************************************************************************************/
//#define null									nullptr
#define null									0
#ifndef __linux__
	#ifndef __APPLE__
		#define uint							unsigned int
		#define ushort							unsigned short
	#endif
	#define ulong								unsigned long long
#else
    #ifdef __ANDROID__
        #define uint                            unsigned int
        #define ushort                          unsigned short
        #define ulong                           unsigned long long
    #endif
#endif

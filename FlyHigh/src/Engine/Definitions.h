#pragma once

#ifdef FH_PLATFORM_WINDOWS
	#ifdef FH_BUILD_DLL
		#define FLYHIGH_API __declspec(dllexport)
	#else
		#define FLYHIGH_API __declspec(dllimport)
	#endif
#else
	#error not supported by platform
#endif 

#pragma once


#ifdef DM_PLATFORM_WINDOWS
	#ifdef DM_BUILD_DLL
		#define DREAM_API __declspec(dllexport)
	#else
		#define DREAM_API __declspec(dllimport)
	#endif
#else
	#error Dream only support Windows!
#endif 

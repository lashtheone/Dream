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

#ifdef DM_ENABLE_ASSERTS
	#define DM_ASSERT(x, ...) { if(!(x)) { DM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define DM_CORE_ASSERT(x, ...) { if(!(x)) { DM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define DM_ASSERT(x, ...)
	#define DM_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
#pragma once
#ifdef DJ_PLATFORM_WINDOWS
	#ifdef DJ_BUILD_DLL
		#define DJ_API __declspec(dllexport)
	#else
		#define DJ_API __declspec(dllimport)
	#endif
#else
	#error DJ Engine only supports Windows!
#endif
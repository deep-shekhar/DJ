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

#define BIT(x) (1 << x)
//included in precompiled header
#include <sstream>
#include <string>
#include <functional>
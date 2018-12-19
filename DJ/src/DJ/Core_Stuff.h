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

#ifdef DJ_ENABLE_ASSERTS
	#define DJ_ASSERT(x, ...) { if(!(x)) { DJ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define DJ_CORE_ASSERT(x, ...) { if(!(x)) { DJ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

#else
	#define DJ_ASSERT(x, ...)
	#define DJ_CORE_ASSERT(x, ...)

#endif


#define BIT(x) (1 << x)


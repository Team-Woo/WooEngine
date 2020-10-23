#pragma once

#ifdef WE_PLATFORM_WINDOWS
	#ifdef WE_BUILD_DLL
		#define WOOENGINE_API __declspec(dllexport)
	#else 
		#define WOOENGINE_API __declspec(dllimport)
	#endif // WE_BUILD_DLL
#else
	#error Woo Engine only supports Windows!
#endif

#ifdef WE_ENABLE_ASSERTS
	#define WE_ASSERT(x, ...) { if(!(x)) { WE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define WE_CORE_ASSERT(x, ...) { if(!(x)) { WE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define WE_ASSERT(x, ...)
	#define WE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
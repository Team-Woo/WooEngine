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
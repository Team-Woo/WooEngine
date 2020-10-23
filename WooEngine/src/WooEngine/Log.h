#pragma once

#include <memory>

#include "Core.h"
#include "spdlog\spdlog.h"
#include "spdlog\fmt\ostr.h"

namespace WE {
	class WOOENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;


	};
}

// Core log macros
#define WE_CORE_TRACE(...)   ::WE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WE_CORE_INFO(...)    ::WE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WE_CORE_WARN(...)    ::WE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WE_CORE_ERROR(...)   ::WE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WE_CORE_FATAL(...)   ::WE::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define WE_TRACE(...)        ::WE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WE_INFO(...)         ::WE::Log::GetClientLogger()->info(__VA_ARGS__)
#define WE_WARN(...)         ::WE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WE_ERROR(...)        ::WE::Log::GetClientLogger()->error(__VA_ARGS__)
#define WE_FATAL(...)        ::WE::Log::GetClientLogger()->fatal(__VA_ARGS__)
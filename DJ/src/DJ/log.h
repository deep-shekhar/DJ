#pragma once

//included in precompiled header
//#include <memory>

#include "Core_Stuff.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace DJ {

	class DJ_API log
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

//Logging Macros
#define DJ_CORE_ERROR(...) ::DJ::log::GetCoreLogger()->error(__VA_ARGS__)
#define DJ_CORE_WARN(...) ::DJ::log::GetCoreLogger()->warn(__VA_ARGS__)
#define DJ_CORE_INFO(...) ::DJ::log::GetCoreLogger()->info(__VA_ARGS__)
#define DJ_CORE_TRACE(...) ::DJ::log::GetCoreLogger()->trace(__VA_ARGS__)
#define DJ_CORE_FATAL(...) ::DJ::log::GetCoreLogger()->fatal(__VA_ARGS__)


#define DJ_ERROR(...) ::DJ::log::GetClientLogger()->error(__VA_ARGS__)
#define DJ_WARN(...) ::DJ::log::GetClientLogger()->warn(__VA_ARGS__)
#define DJ_INFO(...) ::DJ::log::GetClientLogger()->info(__VA_ARGS__)
#define DJ_TRACE(...) ::DJ::log::GetClientLogger()->trace(__VA_ARGS__)
#define DJ_FATAL(...) ::DJ::log::GetClientLogger()->fatal(__VA_ARGS__)
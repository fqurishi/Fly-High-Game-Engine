#pragma once


#include <memory>
#include "Definitions.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace fh {
	class FLYHIGH_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

#define FH_CORE_FATAL(...)	::fh::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define FH_CORE_ERROR(...)	::fh::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FH_CORE_WARN(...)	::fh::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FH_CORE_INFO(...)	::fh::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FH_CORE_TRACE(...)	::fh::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define FH_FATAL(...)		::fh::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define FH_ERROR(...)		::fh::Log::GetClientLogger()->error(__VA_ARGS__)
#define FH_WARN(...)		::fh::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FH_INFO(...)		::fh::Log::GetClientLogger()->info(__VA_ARGS__)
#define FH_TRACE(...)		::fh::Log::GetClientLogger()->trace(__VA_ARGS__)
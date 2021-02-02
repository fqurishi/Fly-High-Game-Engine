#include "Log.h"

namespace fh {
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_ClientLogger = spdlog::stdout_color_mt("Game Application");
		s_CoreLogger = spdlog::stdout_color_mt("Fly High");

		s_ClientLogger->set_level(spdlog::level::trace);
		s_CoreLogger->set_level(spdlog::level::trace);

	}

}
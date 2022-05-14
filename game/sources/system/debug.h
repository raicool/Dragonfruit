#pragma once
#include "utils.h"

namespace Dragonfruit
{
	struct Log
	{
		static std::shared_ptr<spdlog::logger> DebugLogger;

		static void Init();
	};
}

#define DF_LOG_TRACE(...) Dragonfruit::Log::DebugLogger->trace(__VA_ARGS__)
#define DF_LOG_INFO(...)  Dragonfruit::Log::DebugLogger->info(__VA_ARGS__)
#define DF_LOG_WARN(...)  Dragonfruit::Log::DebugLogger->warn(__VA_ARGS__)
#define DF_LOG_ERROR(...) Dragonfruit::Log::DebugLogger->error(__VA_ARGS__)
#define DF_LOG_FATAL(...) Dragonfruit::Log::DebugLogger->critical(__VA_ARGS__)
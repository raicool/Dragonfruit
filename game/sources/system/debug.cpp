#include "pch.h"

#include "debug.h"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Dragonfruit
{
	std::shared_ptr<spdlog::logger> Log::DebugLogger;

	void Log::Init()
	{
		spdlog::sink_ptr consolesink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		spdlog::sink_ptr filesink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("dragonfruit.log");

		consolesink->set_pattern("[%T] : %v");
		filesink->set_pattern("[%T] : %v");

		DebugLogger = std::make_shared<spdlog::logger>("DRAGON", spdlog::sinks_init_list{ consolesink, filesink });
		spdlog::register_logger(DebugLogger);
		spdlog::set_level(spdlog::level::trace);
		spdlog::flush_on(spdlog::level::trace);
	}
}
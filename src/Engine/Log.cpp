#include "Log.hpp"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <vector>

namespace Kea::Log
{
namespace
{
std::shared_ptr<spdlog::logger> logger;
}

void Init()
{
    // Console sink (color)
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] %v");

    // File sink
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("kea_engine.log", true);
    file_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v");

    // Combine sinks
    std::vector<spdlog::sink_ptr> sinks{console_sink, file_sink};
    logger = std::make_shared<spdlog::logger>("kea_engine", sinks.begin(), sinks.end());

    logger->set_level(spdlog::level::trace); // Log all levels by default
    spdlog::set_default_logger(logger);
    spdlog::flush_on(spdlog::level::warn); // Flush logs on warnings/errors

    KEA_LOG_INFO("Logger initialized!");
}

std::shared_ptr<spdlog::logger>& GetLogger()
{
    return logger;
}
} // namespace Kea::Log
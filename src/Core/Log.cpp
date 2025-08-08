#include "Log.hpp"
#include "LogMacros.hpp"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <filesystem>
#include <vector>

namespace Kea
{

void Log::Initialize()
{
    // Console sink (color)
    static auto console_sink = GetConsoleSink();

    std::filesystem::create_directory("Logs");

    for (auto&& name : {"Core", "Renderer", "Events", "Input", "Resources"})
    {
        CreateLogger(name);
    }
}

std::shared_ptr<spdlog::logger> Log::GetLogger(const std::string& name)
{
    auto& map = Loggers();
    auto it = map.find(name);
    if (it != map.end())
    {
        return it->second;
    }

    // If not found, then create it and return it
    return CreateLogger(name);
}

std::shared_ptr<spdlog::logger> Log::CreateLogger(const std::string& name)
{
    auto console_sink = GetConsoleSink();
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("Logs/" + std::string(name) + ".log", true);
    std::vector<spdlog::sink_ptr> sinks{console_sink, file_sink};
    auto logger = std::make_shared<spdlog::logger>(name, sinks.begin(), sinks.end());
    logger->set_pattern("[%8T]%^[%l]%$[%n] %v");
    spdlog::register_logger(logger);
    Loggers().emplace(name, logger);
    return logger;
}

std::unordered_map<std::string, std::shared_ptr<spdlog::logger>>& Log::Loggers()
{
    static std::unordered_map<std::string, std::shared_ptr<spdlog::logger>> loggers;
    return loggers;
}

std::shared_ptr<spdlog::sinks::sink> Log::GetConsoleSink()
{
    static auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    return sink;
}
} // namespace Kea
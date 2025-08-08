#ifndef KEA_CORE_LOG_HPP
#define KEA_CORE_LOG_HPP

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include <memory>
#include <unordered_map>

namespace Kea
{
class Log
{
  public:
    static void Initialize(); // Call at program startup
    static std::shared_ptr<spdlog::logger> GetLogger(const std::string& name);

  private:
    static std::shared_ptr<spdlog::logger> CreateLogger(const std::string& name);
    static std::unordered_map<std::string, std::shared_ptr<spdlog::logger>>& Loggers();
    static std::shared_ptr<spdlog::sinks::sink> GetConsoleSink();
};
} // namespace Kea

#endif /* KEA_CORE_LOG_HPP */

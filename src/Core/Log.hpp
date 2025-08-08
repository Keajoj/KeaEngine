#ifndef KEA_CORE_LOG_HPP
#define KEA_CORE_LOG_HPP

#include <spdlog/fmt/ostr.h> // For streaming custom types
#include <spdlog/spdlog.h>

namespace Kea::Log
{
void Initialize(); // Call at program startup
std::shared_ptr<spdlog::logger>& GetLogger();
} // namespace Kea::Log

// Logging macros
#define KEA_LOG_TRACE(...) ::Kea::Log::GetLogger()->trace(__VA_ARGS__)
#define KEA_LOG_DEBUG(...) ::Kea::Log::GetLogger()->debug(__VA_ARGS__)
#define KEA_LOG_INFO(...) ::Kea::Log::GetLogger()->info(__VA_ARGS__)
#define KEA_LOG_WARN(...) ::Kea::Log::GetLogger()->warn(__VA_ARGS__)
#define KEA_LOG_ERROR(...) ::Kea::Log::GetLogger()->error(__VA_ARGS__)
#define KEA_LOG_CRITICAL(...) ::Kea::Log::GetLogger()->critical(__VA_ARGS__)

// Optionally strip TRACE and DEBUG in release
#ifdef NDEBUG
#undef KEA_LOG_TRACE
#define KEA_LOG_TRACE(...)
#undef KEA_LOG_DEBUG
#define KEA_LOG_DEBUG(...)
#endif

#endif /* KEA_CORE_LOG_HPP */

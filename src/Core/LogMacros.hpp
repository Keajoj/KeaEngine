#ifndef KEA_CORE_LOGMACROS_HPP
#define KEA_CORE_LOGMACROS_HPP

// Logging macros
#define KEA_LOG_TRACE(subsystem, ...) ::Kea::Log::GetLogger(subsystem)->trace(__VA_ARGS__);
#define KEA_LOG_DEBUG(subsystem, ...) ::Kea::Log::GetLogger(subsystem)->debug(__VA_ARGS__)
#define KEA_LOG_INFO(subsystem, ...) ::Kea::Log::GetLogger(subsystem)->info(__VA_ARGS__)
#define KEA_LOG_WARN(subsystem, ...) ::Kea::Log::GetLogger(subsystem)->warn(__VA_ARGS__)
#define KEA_LOG_ERROR(subsystem, ...) ::Kea::Log::GetLogger(subsystem)->error(__VA_ARGS__)
#define KEA_LOG_CRITICAL(subsystem, ...) ::Kea::Log::GetLogger(subsystem)->critical(__VA_ARGS__)

// Optionally strip TRACE and DEBUG in release
#ifdef NDEBUG
#undef KEA_LOG_TRACE
#define KEA_LOG_TRACE(...)
#undef KEA_LOG_DEBUG
#define KEA_LOG_DEBUG(...)
#endif

#endif /* KEA_CORE_LOGMACROS_HPP */

#pragma once

#include <glog/logging.h>

enum class LogLevel { INFO, WARNING, ERROR, FATAL };

class Logger {
public:
  Logger(const char *program_name);
  ~Logger();

  void SetLogLevel(LogLevel level);
  void LogMessage(LogLevel level, const char *file, int line,
                  const char *message);

private:
  google::LogSeverity glog_level;
};

// 定义宏，方便使用日志
#define LOG_INFO(message)                                                      \
  Logger(__FILE__).LogMessage(LogLevel::INFO, __FILE__, __LINE__, (message))
#define LOG_WARNING(message)                                                   \
  Logger(__FILE__).LogMessage(LogLevel::WARNING, __FILE__, __LINE__, (message))
#define LOG_ERROR(message)                                                     \
  Logger(__FILE__).LogMessage(LogLevel::ERROR, __FILE__, __LINE__, (message))
#define LOG_FATAL(message)                                                     \
  Logger(__FILE__).LogMessage(LogLevel::FATAL, __FILE__, __LINE__, (message))

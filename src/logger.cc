#include "logger.h"

Logger::Logger(const char *program_name) : glog_level(google::GLOG_INFO) {
  google::InitGoogleLogging(program_name);
}

Logger::~Logger() { google::ShutdownGoogleLogging(); }

void Logger::SetLogLevel(LogLevel level) {
  switch (level) {
  case LogLevel::INFO:
    glog_level = google::GLOG_INFO;
    break;
  case LogLevel::WARNING:
    glog_level = google::GLOG_WARNING;
    break;
  case LogLevel::ERROR:
    glog_level = google::GLOG_ERROR;
    break;
  case LogLevel::FATAL:
    glog_level = google::GLOG_FATAL;
    break;
  default:
    glog_level = google::GLOG_INFO;
  }
  FLAGS_minloglevel = static_cast<int>(glog_level);
}

void Logger::LogMessage(LogLevel level, const char *file, int line,
                        const char *message) {
  switch (level) {
  case LogLevel::INFO:
    LOG(INFO) << "[" << file << ":" << line << "] " << message;
    break;
  case LogLevel::WARNING:
    LOG(WARNING) << "[" << file << ":" << line << "] " << message;
    break;
  case LogLevel::ERROR:
    LOG(ERROR) << "[" << file << ":" << line << "] " << message;
    break;
  case LogLevel::FATAL:
    LOG(FATAL) << "[" << file << ":" << line << "] " << message;
    break;
  default:
    LOG(INFO) << "[" << file << ":" << line << "] " << message;
  }
}

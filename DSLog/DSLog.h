#ifndef _DSLOG_H
#define _DSLOG_H

#include <string>
#include <cstdarg>

enum DSLogLevel{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

// Basic logging functions
void Log(DSLogLevel level, const char* message);
void Log(DSLogLevel level, const std::string& message);

// Formatted logging with file/line info
void Logf(DSLogLevel level, const char* file, int line, const char* format, ...);

// Convenience macros
#define LOG_DEBUG(msg) Logf(DEBUG, __FILE__, __LINE__, msg)
#define LOG_INFO(msg) Logf(INFO, __FILE__, __LINE__, msg)
#define LOG_WARNING(msg) Logf(WARNING, __FILE__, __LINE__, msg)
#define LOG_ERROR(msg) Logf(ERROR, __FILE__, __LINE__, msg)
#define LOG_CRITICAL(msg) Logf(CRITICAL, __FILE__, __LINE__, msg)

// Formatted convenience macros
#define LOG_DEBUG_F(fmt, ...) Logf(DEBUG, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_INFO_F(fmt, ...) Logf(INFO, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_WARNING_F(fmt, ...) Logf(WARNING, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_ERROR_F(fmt, ...) Logf(ERROR, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_CRITICAL_F(fmt, ...) Logf(CRITICAL, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

#endif //_DSLOG_H

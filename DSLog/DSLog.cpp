#include "DSLog.h"
#include <cstdio>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <cstring>

// ANSI color codes
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[1;31m"
#define COLOR_YELLOW  "\033[1;33m"
#define COLOR_GREEN   "\033[1;32m"
#define COLOR_BLUE    "\033[1;34m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN    "\033[1;36m"

// Internal helper to get label and color
const char* GetLogLabel(DSLogLevel level) {
    switch (level) {
        case DEBUG:    return "[ DEBUG  ]";
        case INFO:     return "[  INFO  ]";
        case WARNING:  return "[ WARNING]";
        case ERROR:    return "[  ERROR ]";
        case CRITICAL: return "[CRITICAL]";
        default:       return "[ UNKNOWN]";
    }
}

const char* GetLogColor(DSLogLevel level) {
    switch (level) {
        case DEBUG:    return COLOR_CYAN;
        case INFO:     return COLOR_GREEN;
        case WARNING:  return COLOR_YELLOW;
        case ERROR:    return COLOR_RED;
        case CRITICAL: return COLOR_MAGENTA;
        default:       return COLOR_RESET;
    }
}

// Get current timestamp
std::string GetTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()) % 1000;

    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_t), "%H:%M:%S");
    ss << '.' << std::setfill('0') << std::setw(3) << ms.count();
    return ss.str();
}

// Extract filename from full path
const char* GetFilename(const char* path) {
    const char* filename = strrchr(path, '/');
    return filename ? filename + 1 : path;
}

void Log(DSLogLevel level, const char* message) {
    const char* color = GetLogColor(level);
    const char* label = GetLogLabel(level);
    printf("%s%s [%s] %s%s\n", color, label, GetTimestamp().c_str(), message, COLOR_RESET);
}

void Log(DSLogLevel level, const std::string& message) {
    Log(level, message.c_str());
}

void Logf(DSLogLevel level, const char* file, int line, const char* format, ...) {
    const char* color = GetLogColor(level);
    const char* label = GetLogLabel(level);
    const char* filename = GetFilename(file);

    // Format the message
    char buffer[1024];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    printf("%s%s [%s] %s:%d - %s%s\n",
           color, label, GetTimestamp().c_str(), filename, line, buffer, COLOR_RESET);
}

#include "DSLog.h"
#include <cstdio>
#include <iostream>

// ANSI color codes
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[1;31m"
#define COLOR_YELLOW  "\033[1;33m"
#define COLOR_GREEN   "\033[1;32m"

// Internal helper to get label and color
const char* GetLogLabel(DSLogLevel level) {
    switch (level) {
        case INFO:     return "[  INFO  ]";
        case ERROR:    return "[  ERROR ]";
        case WARNNING: return "[WARNNING]";
        default:       return "[ UNKNOWN]";
    }
}

const char* GetLogColor(DSLogLevel level) {
    switch (level) {
        case INFO:     return COLOR_GREEN;
        case ERROR:    return COLOR_RED;
        case WARNNING: return COLOR_YELLOW;
        default:       return COLOR_RESET;
    }
}

void Log(DSLogLevel level, const char* message) {
    const char* color = GetLogColor(level);
    const char* label = GetLogLabel(level);
    printf("%s%s %s%s\n", color, label, message, COLOR_RESET);
}

void Log(DSLogLevel level, const std::string& message) {
    const char* color = GetLogColor(level);
    const char* label = GetLogLabel(level);
    std::cout << color << label << " " << message << COLOR_RESET << "\n";
}

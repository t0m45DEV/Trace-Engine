#include "log.h"

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_GREY    "\x1b[90m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define ANSI_BOLD "\e[1m"

#define DATA_COLOR   ANSI_COLOR_GREY
#define DEBUG_COLOR  ANSI_COLOR_GREEN
#define INFO_COLOR    ANSI_COLOR_CYAN
#define WARNING_COLOR ANSI_COLOR_YELLOW
#define ERROR_COLOR   ANSI_COLOR_RED ANSI_BOLD

typedef struct {
    int hour;
    int min;
    int sec;
    int line;
    const char* file_name;
    const char* color;
    const char* message_name;
} message_info;

void print_message(const message_info info, const char* message, va_list arg)
{
    printf(DATA_COLOR "[ %02d:%02d:%02d ] ", info.hour, info.min, info.sec);
    printf("%s%s" ANSI_COLOR_RESET, info.color, info.message_name);
    printf(DATA_COLOR "%s:%i: " ANSI_COLOR_RESET, info.file_name, info.line);
    vprintf(message, arg);
    printf("\n" ANSI_COLOR_RESET);
}

void log_message(const log_levels_t log_level, const char* file_name, const int line, const char* message, ...)
{
    time_t rawtime;
    struct tm * timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    message_info info = {
        .hour = timeinfo->tm_hour,
        .min = timeinfo->tm_min,
        .sec = timeinfo->tm_sec,
        .line = line,
        .file_name = file_name
    };

    switch (log_level)
    {
        case _LOG_LEVEL_DEBUG:
            info.color = DEBUG_COLOR;
            info.message_name = "DEBUG ";
            break;

        case _LOG_LEVEL_INFO:
            info.color = INFO_COLOR;
            info.message_name = "INFO  ";
            break;

        case _LOG_LEVEL_WARNING:
            info.color = WARNING_COLOR;
            info.message_name = "WARN  ";
            break;

        case _LOG_LEVEL_ERROR:
            info.color = ERROR_COLOR;
            info.message_name = "ERROR ";
            break;
    }

    if (!message) {
        print_message(info, "Invalid log message\n", NULL);
        return;
    }

    va_list arg;
    va_start(arg, message);

    print_message(info, message, arg);
    
    va_end(arg);
}

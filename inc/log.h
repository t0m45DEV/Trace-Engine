#ifndef _H_LOG
#define _H_LOG

#define GET_VARIABLE_NAME(X) #X

#ifndef GAME_EXPORT
    #define log_debug(...)   (log_message(_LOG_LEVEL_DEBUG, __FILE__, __LINE__, __VA_ARGS__))
    #define log_info(...)    (log_message(_LOG_LEVEL_INFO, __FILE__, __LINE__, __VA_ARGS__))
#else
    #define log_debug(...)   // Does nothing
    #define log_info(...)    // Does nothing
#endif

#define log_warning(...) (log_message(_LOG_LEVEL_WARNING, __FILE__, __LINE__, __VA_ARGS__))
#define log_error(...)   (log_message(_LOG_LEVEL_ERROR, __FILE__, __LINE__, __VA_ARGS__))

typedef enum {
    _LOG_LEVEL_DEBUG,
    _LOG_LEVEL_INFO,
    _LOG_LEVEL_WARNING,
    _LOG_LEVEL_ERROR,
} log_levels_t;

void log_message(const log_levels_t log_level, const char* file_name, const int line, const char* message, ...);

#endif
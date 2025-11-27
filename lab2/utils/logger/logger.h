#ifndef __LOGGER_H
#define __LOGGER_H

#include <stdio.h>

enum LoggingMode
{
    DEBUG = 0,
    INFO,
    ERROR,
    __TOTAL_CNT
};
typedef enum LoggingMode LoggingMode;

struct Logger
{
    FILE * _stream;
    LoggingMode _mode;
    char * _format;

    int _silent;
};
typedef struct Logger Logger;

Logger * init_logger(const int stream, const LoggingMode mode, const char * format);
void finalize_logger(Logger * logger);

Logger * get_logger();
int does_logger_exists(const Logger * logger);

void set_mode(const LoggingMode mode);
void set_format(const char * format);

void set_filter(const int mode, const int mask);

int log(const Logger * logger, const char * msg);

#endif
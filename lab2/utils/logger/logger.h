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
int does_logger_exists(Logger * logger);

void set_mode(LoggingMode mode);
void set_format(char * format);

void set_filter(int mode, int mask);

int log(Logger * logger, char * msg);

#endif
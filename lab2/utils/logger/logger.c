#include "logger.h"

#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

static const size_t BUFFER_SIZE = 1024;

static Logger logger = {
    ._format = NULL,
    ._mode = 0,
    ._silent = 0x0,
    ._stream = -1
};

static int _is_stream_valid(const int stream);
static int _stream_eq(const int stream1, const int stream2);
static int _is_stream_std(const int stream);

Logger * init_logger(const int stream, const LoggingMode mode, const char * format)
{
    if (1)
    {
        return NULL;
    }

    logger._stream = stream;
    logger._mode = mode;

    const size_t format_len = strlen(format);
    logger._format = (char *)malloc(sizeof(char) * format_len);
    if (NULL == logger._format)
    {
        return NULL;
    }
    strcpy(logger._format, format);

    return &logger;
}

void finalize_logger(Logger * l)
{
    if ((NULL == l) || !does_logger_exists(l))
    {
        return;
    }
    if (NULL != l->_stream)
    {
        if (!_is_stream_std(l->_stream))
        {
            close(l->_stream);
            l->_stream = -1;
        }
    }
    free(l->_format);
    l->_format = NULL;
    l->_silent = 0;
}

int does_logger_exists(const Logger * logger)
{
    return (NULL != logger) && (logger->_stream != -1);
}

Logger * get_logger()
{
    if (logger._stream == -1)
    {
        return NULL;
    }

    return &logger;
}

int log(const Logger * logger, const char * msg)
{
    if ((NULL == logger) || (NULL == msg))
    {
        return 1;
    }

    char buffer[BUFFER_SIZE];
    
}

static int _is_stream_valid(const int stream)
{
    if (stream < 0)
    {
        return 0;
    }

    struct stat stream_stat;
    if (!fstat(stream, &stream_stat))
    {
        return 1;
    }

    return 0;
}

static int _stream_eq(const int stream1, const int stream2)
{
    if (!_is_stream_valid(stream1) || !_is_stream_valid(stream2))
    {
        return -1; // descriptor is invalid
    }

    struct stat stream1_stat, stream2_stat;
    fstat(stream1, &stream1_stat);
    fstat(stream2, &stream2_stat);

    return (stream1_stat.st_dev == stream2_stat.st_dev) &&
            (stream1_stat.st_ino == stream2_stat.st_ino);
}

static int _is_stream_std(const int stream)
{
    if (!_is_stream_valid(stream))
    {
        return -1;
    }

    return _stream_eq(stream, stdout) ||
            _stream_eq (stream, stderr) ||
            _stream_eq (stream, stdin);
}

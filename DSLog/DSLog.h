#ifndef _DSLOG_H
#define _DSLOG_H

#include <string>

enum DSLogLevel{
    INFO,
    ERROR,
    WARNNING
};

// for clang
void Log(DSLogLevel level,const char * message);

// for cpp
void Log(DSLogLevel level,const std::string &message);

#endif //_DSLOG_H

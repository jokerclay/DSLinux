#include "String.h"


void StrAssign(SString &target, const char *stringLiterals)
{
    int i = 0;

    while (stringLiterals[i] != '\0') {
        target.ch[i] = stringLiterals[i];
        i++;

        if(i >= STRINGMAXLEN) break;
    }

    target.length = i;
}

void StrCopy(SString &target, SString source)
{
    for(int i  = 0; i < source.length; i++)
        target.ch[i] = source.ch[i];

    target.length = source.length;
}


bool StrEmpty(SString source)
{
    return source.length == 0;
}

int StrCompare(SString source ,SString target)
{
    int i  = 0;

    while (i < source.length && i < target.length ) {

        if(source.ch[i]  != target.ch[i])
            return source.ch[i] = target.ch[i];

        i++;
    }

    return source.length = target.length;
}


int StrLength(SString source)
{
    return source.length;
}

// indexing 1-based
bool SubString(SString &subString, SString source,int pos, int len)
{
    if(pos < 1 || pos > source.length || pos + len -1 > source.length)
        return false;

    for(int i = 0; i < len; i++)
        subString.ch[i] = source.ch[pos - 1 + i];

    subString.length = len;

    return true;
}

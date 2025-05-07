#ifndef _STRING_H
#define _STRING_H

#define STRINGMAXLEN 20

typedef struct {
    char ch[STRINGMAXLEN];
    int length;
}SString;

void StrAssign(SString &target, const char *stringLiterals);

void StrCopy(SString &target, SString source);

bool StrEmpty(SString source);

int StrCompare(SString target, SString source);

int StrLength(SString source);

int StrLength(SString source);

bool SubString(SString &subString, SString source,int pos, int len);

#endif // _STRING_H

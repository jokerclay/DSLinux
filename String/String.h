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

bool Concat(SString &target, SString source1, SString source2);

int Index(SString source, SString target);

int Index2(SString source, SString target);

void ClearString(SString &source);

void DestoryString(SString &source); // memory allocate on stack, no need for this.

#endif // _STRING_H

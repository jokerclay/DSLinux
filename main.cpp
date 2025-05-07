#include "main.h"
#include "DSLog/DSLog.h"
#include "String/String.h"
#include <cstdio>
#include <string>

int main()
{
    SString source = {0};
    SString target  = {0};

    if (StrEmpty(source)) 
        Log(INFO, "source is empty");
    else
        Log(INFO, "source is  NOT empty");

    if (StrEmpty(target)) 
        Log(INFO, "target is empty");
    else
        Log(INFO, "target is  NOT empty");



    StrAssign(source, "this is a test content");


    if (StrEmpty(source)) 
        Log(INFO, "source is empty");
    else
        Log(INFO, "source is  NOT empty");

    if (StrEmpty(target)) 
        Log(INFO, "target is empty");
    else
        Log(INFO, "target is  NOT empty");



    StrCopy(target, source);


    if (StrEmpty(source)) 
        Log(INFO, "source is empty");
    else
        Log(INFO, "source is  NOT empty");

    if (StrEmpty(target)) 
        Log(INFO, "target is empty");
    else
        Log(INFO, "target is  NOT empty");



    SString s1 ={0};
    SString s2 ={0};

    StrAssign(s1, "apple");
    StrAssign(s2, "apricot");

    int res = StrCompare(s1, s2);

    if(res < 0)
        Log(INFO, "apple < apricot");
    else if (res  == 0)
        Log(INFO, "apple = apricot");
    else
        Log(INFO, "apple > apricot");


    Log(INFO, "s1: apple length : " + std::to_string(StrLength(s1)));


    SString s3 ={0};
    SString s3sub ={0};
    StrAssign(s3, "computer");

    if(SubString(s3sub, s3,2,3))
    {
        Log(INFO, "\"computer\" from position 2 add length 3 compose to substring:");
        for(int i =0; i < s3sub.length; i++)
            putchar(s3sub.ch[i]);

        putchar('\n');
    }else {
        Log(ERROR, "Invalid substring range");
    }





    return 0;
}

#include "../../DSLog/DSLog.h"
#include "../../String/String.h"

int main()
{
    SString source = {0};
    SString target  = {0};

    // StrEmpty
    if (StrEmpty(source)) 
        Log(INFO, "source is empty");
    else
        Log(INFO, "source is  NOT empty");

    if (StrEmpty(target)) 
        Log(INFO, "target is empty");
    else
        Log(INFO, "target is  NOT empty");



    // StrAssign
    StrAssign(source, "this is a test content");


    if (StrEmpty(source)) 
        Log(INFO, "source is empty");
    else
        Log(INFO, "source is  NOT empty");

    if (StrEmpty(target)) 
        Log(INFO, "target is empty");
    else
        Log(INFO, "target is  NOT empty");



    // StrCopy
    StrCopy(target, source);


    if (StrEmpty(source)) 
        Log(INFO, "source is empty");
    else
        Log(INFO, "source is  NOT empty");

    if (StrEmpty(target)) 
        Log(INFO, "target is empty");
    else
        Log(INFO, "target is  NOT empty");




    // StrCompare
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


    // SubString
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

    // Concat 1
    SString s4 ={0};
    SString s5 ={0};
    SString T1 ={0};
    StrAssign(s4, "data");
    StrAssign(s5, "base");


    if(Concat(T1, s4, s5))
    {
        Log(INFO, "Concatented:");
        for (int i =0; i < T1.length; i++) 
            putchar(T1.ch[i]);

        putchar('\n');
    }else {
        Log(ERROR, "Concat falied: result too long, expected less than " + std::to_string(STRINGMAXLEN));
    }

    // Concat 2
    SString s6 ={0};
    SString s7 ={0};
    SString T2 ={0};
    StrAssign(s6, "aaaaaaaaaaaaaa");
    StrAssign(s7, "bbbbbbbbbbbbbb");


    if(Concat(T2, s6, s7))
    {
        Log(INFO, "Concatented:");
        for (int i =0; i < T2.length; i++) 
            putchar(T2.ch[i]);

        putchar('\n');
    }else {
        Log(ERROR, "Concat falied: result too long, expected less than " + std::to_string(STRINGMAXLEN) + " characters.");
    }

    // Index
    SString s8 ={0};
    SString T3 ={0};
    StrAssign(s8, "abcdefg");
    StrAssign(T3, "cde");
    int pos = Index(s8, T3);

    Log(INFO, "the Index of \"cde\" in \"abcdefg\" :" + std::to_string(pos));


    // ClearString
    ClearString(T3);
    if (StrEmpty(T3)) 
        Log(INFO, "T3 has been cleared");
    else
        Log(INFO, "T3 are NOT cleared");

    return 0;
}




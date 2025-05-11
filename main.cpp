#include "main.h"
#include "DSLog/DSLog.h"
#include "String/String.h"

int main()
{
    // Index
    SString s8 ={0};
    SString T3 ={0};
    StrAssign(s8, "abcdefg");
    StrAssign(T3, "cde");
    int pos = Index(s8, T3);
    int pos2 = Index2(s8, T3);

    Log(INFO, "the Index of \"cde\" in \"abcdefg\" :" + std::to_string(pos));
    Log(INFO, "the Index of \"cde\" in \"abcdefg\" :" + std::to_string(pos2));

    return 0;
}

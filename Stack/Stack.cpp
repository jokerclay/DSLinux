#include "Stack.h"

void sqStackInitStack(sqStack &S)
{
    S.top =-1;
}


bool sqStackStackEmpty  (sqStack S)
{
    return  S.top == -1;
}


bool sqStackPush(sqStack &S, sqStackElementType e)
{
    if(S.top > sqStackMaxSize - 1)
        return false;
    S.data[++S.top] = e;
    return true;
}

bool sqStackGetTop (sqStack S,sqStackElementType &topValue)
{
    if(S.top <=-1) return false;

    topValue = S.data[S.top];
    return true;
}

#include "main.h"
#include "DSLog/DSLog.h"
#include "Stack/Stack.h"
#include <cstdio>

#define  LEFT_ROUND_BRACKET  '('
#define RIGHT_ROUND_BRACKET  ')'

#define  LEFT_SQUARE_BRACKET '['
#define RIGHT_SQUARE_BRACKET ']'

#define  LEFT_CURLY_BRACKET  '{'
#define RIGHT_CURLY_BRACKET  '}'



bool isLeftBracket(char bracket)
{
    if((bracket == LEFT_ROUND_BRACKET )  ||
        (bracket == LEFT_SQUARE_BRACKET) ||
        (bracket == LEFT_CURLY_BRACKET))
    {
        return true;
    }
    return false ;
}

bool isRightBracket(char bracket)
{
    if((bracket == RIGHT_ROUND_BRACKET  )  ||
        (bracket == RIGHT_SQUARE_BRACKET ) ||
        (bracket == RIGHT_CURLY_BRACKET))
    {
        return true;
    }
    return false ;
}

bool bracketMatched(char newComer, char stackTop)
{
    if(stackTop == LEFT_CURLY_BRACKET && newComer == RIGHT_CURLY_BRACKET)
        return true;

    if(stackTop == LEFT_ROUND_BRACKET && newComer == RIGHT_ROUND_BRACKET)
        return true;

    if(stackTop == LEFT_SQUARE_BRACKET && newComer == RIGHT_SQUARE_BRACKET)
        return true;

    return false;
}

int main()
{

    /*bracketmatching.cpp*/

    // 1.read all the bracket into a empty stack squenenly

    FILE  *testCaseFile;
    char filePath[] = "./objs/bracketMathchingCase1.txt";
    char singleChar;

    sqStack S;
    sqStackInitStack(S);

    testCaseFile = fopen(filePath, "r");
    if(testCaseFile == NULL)
    {
        Log(ERROR,"Can't open test case file" );
        return 1;
    }

    while ((singleChar  = fgetc(testCaseFile))!=EOF) {
        /*putchar(singleChar);*/
        if(isLeftBracket(singleChar))
        {
            // printf("%c: is left\n",singleChar);
            sqStackPush(S,singleChar);
        }else if(isRightBracket(singleChar)){
            // printf("%c: is right\n",singleChar);
            int currentTop;
            int popedValue;

            if(sqStackStackEmpty(S)) {
                printf("Unmatched closing bracket: %c \n", singleChar);
                return 1;
            }

            sqStackGetTop(S,currentTop);
            if(bracketMatched(singleChar, currentTop))
            {
                sqStackPop(S, popedValue);
            }else {
                printf("Unmatched character %c\n", singleChar);
            }
        }
    }

    fclose(testCaseFile);

    if (sqStackStackEmpty(S)) {
        Log(INFO, "All brackets are matched");
    } else {
        Log(ERROR, "Unmatched opening brackets remain in the stack");
    }
}


#include "Stack.h"
#include <cstdlib>
#include <cstdio>
#include "../DSLog/DSLog.h"


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

bool sqStackPop (sqStack &S,sqStackElementType &popedValue)
{
    if(S.top <= -1)
        return false;

    popedValue = S.data[S.top];
    S.top-=1;
    return true;
};

bool sqStackGetTop (sqStack S,sqStackElementType &topValue)
{
    if(S.top <=-1) return false;

    topValue = S.data[S.top];
    return true;
}

void linkedStackInitStack(linkedStack &S)
{
    stackNode *head_node = (stackNode *)malloc(sizeof(stackNode));
    if (head_node == NULL) {
        LOG_ERROR("Memory allocation failed in linkedStackInitStack");
        S = NULL;
        return;
    }
    head_node->data = 0;
    head_node->next = NULL;
    S = head_node;
}

bool linkedStackStackEmpty(linkedStack S)
{
    if(S == NULL) return false;
    return S->next == NULL;
}

bool linkedStackPush (linkedStack &S, sqStackElementType e)
{
    if(S == NULL) return false;
    stackNode *new_node = (stackNode *)malloc(sizeof(stackNode));
    if (new_node == NULL) {
        LOG_ERROR("Memory allocation failed in linkedStackPush");
        return false;
    }

    new_node->next = S->next;
    new_node->data = e;
    S->next =new_node;
    return true;
}

bool linkedStackGetTop (linkedStack S,sqStackElementType &topValue)
{
    if (S== NULL || S->next== NULL) return false;
    topValue = S->next->data;
    return true;
}

bool linkedStackPop(linkedStack &S,sqStackElementType &e)
{
    if (S== NULL || linkedStackStackEmpty(S)) return false;

    // get top value
    linkedStackGetTop(S,e);

    // skip and free the top node
    stackNode *temp = S;
    temp= S->next->next;
    free(S->next);
    S->next = temp;

    return true;
}

void linkedStackDestoryStack(linkedStack &S)
{
    stackNode *temp;
    while (S !=NULL) {
        temp = S;
        S = S->next;
        free(temp);
    }
}

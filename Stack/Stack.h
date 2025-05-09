#ifndef _STACK_H
#define _STACK_H

// sqStack base on array
#define sqStackMaxSize 50
#define sqStackElementType int
typedef struct
{
    sqStackElementType data[sqStackMaxSize];
    int top;
}sqStack;

void sqStackInitStack   (sqStack &S);
bool sqStackStackEmpty  (sqStack S);
bool sqStackPush        (sqStack &S,sqStackElementType e);
bool sqStackPop         (sqStack &S,sqStackElementType &popedValue);
bool sqStackGetTop      (sqStack S ,sqStackElementType &topValue);
void sqStackDestoryStack(sqStack &S); // Since sqStack is implemented base on array,
                                      // it will be destoryed automatically when the
                                      // program is done.


#define linkedStackElementType int
typedef struct stackNode
{
    linkedStackElementType data;
    struct stackNode *next;
}stackNode, *linkedStack;


void linkedStackInitStack   (linkedStack &S);
bool linkedStackStackEmpty  (linkedStack S);
bool linkedStackPush        (linkedStack &S, sqStackElementType e);
bool linkedStackPop         (linkedStack &S,sqStackElementType &e);
bool linkedStackGetTop      (linkedStack S,sqStackElementType &topValue);
void linkedStackDestoryStack(linkedStack &S);


#endif // _STACK_H

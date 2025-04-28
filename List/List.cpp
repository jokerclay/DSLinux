#include "List.h"
#include <cstdio>
#include <cstdlib>

void squenceInitList(SqList &L)
{
    L.length=0;
};

int squenceLength(SqList L) 
{
    return L.length;
};

// return index start from 1
int squenceLocateElem(SqList L, SqElemetType e)
{
    for(int i = 0; i < L.length; i++ )
    {
        if(L.data[i] == e)
        {
            return i+1;
        }
    }
    return -1;
};


// i aka index,assume it start from 1
bool squenceGetElem(SqList L, int i, SqElemetType &out)
{
    if(i < 0 || i > L.length ) return false;
    out = L.data[i-1];
    return true;
};

bool squenceListInsert(SqList &L, int i, SqElemetType e)
{
    if(i < 0 || i > L.length+1 ) return false;

    if(L.length >= SqMaxSize ) return false;

    for(int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
};

bool squenceListDelete(SqList &L, int i,SqElemetType &removed)
{
    if(i < 1 ||i > L.length) return false;
    removed= L.data[i-1];

    for(int j = i;j < L.length;j++)
        L.data[j-1] = L.data[j];

    L.length--;
    return true;
};


void squencePrintList(SqList L)
{
    printf("[");
    for(int i= 0; i < L.length; i++)
    {
        printf("%d ",L.data[i]);
    }
    printf("]");
    printf("\n");
};

bool squenceEmpty(SqList L)
{
    return L.length == 0;
};

void squenceDestroyList()
{

};


void linkedInitList(LinkedList &L)
{
    L.data = (LinkedElemetType *)malloc(LinkedInitSize * sizeof(LinkedElemetType));
    L.length = 0;
    L.maxsize = LinkedInitSize;
};

void linkedLength() 
{

};

void linkedLocateElem() 
{

};

void linkedGetElem() 
{

};

void linkedListInsert() 
{

};
void linkedListDelete() 
{

};
void linkedPrintList() 
{

};
void linkedEmpty() 
{

};
void linkedDestroyList() 
{

};

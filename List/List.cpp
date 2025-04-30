#include "List.h"
#include <cstddef>
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

bool linkedInitList(LinkedList &L)
{
    L = (LNode*)malloc(sizeof(LNode)); // 头指针指向头节点
    L->next = NULL;
    return true; 
};

int linkedLength(LinkedList L)
{
    int len = 0;
    LNode *temp = L;
    while (temp->next != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
};

LNode* linkedLocateElem(LinkedList L, int i)
{
    LNode *temp = L;
    int j = 0;
    while (temp!=NULL && j<i) {
        temp = temp->next;
    }
    return temp;
};

LNode* linkedGetElem(LinkedList L, LinkedElemetType e)
{
    LNode *temp = L;
    while (temp->data!= e) {
        temp = temp->next;
    }
    return temp;
};

void linkedListHeadInsert()
    {

    };

void linkedListTailInsert()
    {

    };


bool linkedListInsert(LinkedList L , int i ,LinkedElemetType e)
{
    LNode *temp = L;
    int j = 0;

    while (temp != NULL && j < i - 1) {
        temp = temp->next;
        j++;
    }

    if(temp == NULL)
        return false;

    LNode *newNode = (LNode * )malloc(sizeof(LNode));
    newNode->data= e;
    newNode->next= temp->next;
    temp->next = newNode;
    return true;
};

bool linkedListDelete(LinkedList &L, int i, LinkedElemetType &removed)
{
    LNode *temp = L;
    int j = 0;

    while (temp->next!=NULL && j < i -1) {
        temp = temp->next;
        j++;
    }

    if(temp->next == NULL || j > i-1)
        return false;

    LNode *removedNode = temp->next;
    temp->next = removedNode->next;
    removed = removedNode->data;
    free(removedNode);
    return true;
};


void linkedPrintList(LinkedList L)
{
    if(L == NULL) 
    {
        printf("LinkedList NOT exists\n.");
        return;
    }
    LNode *temp = L;
    while (temp->next != NULL) {
        temp = temp->next;
        printf("%d -> ",temp->data);
    }
    printf("NULL \n");
};



bool linkedEmpty(LinkedList L)
{
    return L->next == NULL ;
};

void linkedDestroyList(LinkedList &L)
{
    LNode *temp;
    while (L !=NULL) {
        temp = L;
        L=L->next;
        free(temp);
    }
};

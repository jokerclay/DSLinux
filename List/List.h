#ifndef  _LIST_H
#define  _LIST_H

// squence list [a,b,c]
#define SqElemetType int
#define SqMaxSize  50
typedef struct
{
    SqElemetType data[SqMaxSize];
    int length;
} SqList;


void squenceInitList    (SqList &L);
int  squenceLength      (SqList L);
int  squenceLocateElem  (SqList L, SqElemetType e);
bool squenceGetElem     (SqList L, int i,SqElemetType &out);
bool squenceListInsert  (SqList &L, int i, SqElemetType e);
bool squenceListDelete  (SqList &L, int i,SqElemetType &removed);
void squencePrintList   (SqList L);
bool squenceEmpty       (SqList L);
void squenceDestroyList (); // since SqList is declared on the stack,
                            // it will be destoryed automatically when the program is done.

// linked list a -> b -> c
#define LinkedElemetType int
typedef struct LNode
{
    LinkedElemetType data;
    struct LNode *next;
}LNode, *LinkedList;

bool   linkedInitList    (LinkedList &L);
int    linkedLength      (LinkedList L);
LNode* linkedLocateElem  (LinkedList L, int i);
LNode* linkedGetElem     (LinkedList L, LinkedElemetType e);
bool   linkedListInsert  (LinkedList L , int i ,LinkedElemetType e);
void   linkedListHeadInsert();
void   linkedListTailInsert();
bool   linkedListDelete(LinkedList &L, int i, LinkedElemetType &removed);
void   linkedPrintList(LinkedList L);
bool   linkedEmpty(LinkedList L);
void   linkedDestroyList(LinkedList &L);

#endif

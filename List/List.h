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
#define LinkedElementType int
typedef struct LNode
{
    LinkedElementType data;
    struct LNode *next;
}LNode, *LinkedList;

bool   linkedInitList      (LinkedList &L);
int    linkedLength        (LinkedList L);
LNode* linkedLocateElem    (LinkedList L, int i);
LNode* linkedGetElem       (LinkedList L, LinkedElementType e);
bool   linkedListInsert    (LinkedList L, int i ,LinkedElementType e);
bool   linkedListHeadInsert(LinkedList &L, LinkedElementType e);
bool   linkedListTailInsert(LinkedList &L, LinkedElementType e);
bool   linkedListDelete    (LinkedList &L, int i, LinkedElementType &removed);
void   linkedPrintList     (LinkedList L);
bool   linkedEmpty         (LinkedList L);
void   linkedDestroyList   (LinkedList &L);


// double linked list a <=> b <=> c
#define DoubleLinkedElemetType int
typedef struct DNode
{
    LinkedElementType data;
    struct LNode *prior,*next;
}DNode, *DLinkedList;



// CircularLinkedList a -> b -> c-+
//                    ^           |
//                    ------------+
typedef struct CNode {
    LinkedElementType data;
    struct CNode *next;
} CNode, *CircularLinkedList;



//                   +--------------+
//                   v              |
// CircularLinkedList a <=> b <=> c==
//                     ^            |
//                     -------------+
#define DoubleCircularElementType int

typedef struct DCNode {
    DoubleCircularElementType data;
    struct DCNode *prior;
    struct DCNode *next;
} DCNode, *CircularDoublyLinkedList;



#define StaticElementType int
#define StaticMaxSize 100

typedef struct {
    StaticElementType data;
    int next;  // 指向下一个元素的“下标”
} StaticNode;

typedef struct {
    StaticNode nodes[StaticMaxSize];
    int head;   // 指向第一个有效元素
    int free;   // 指向第一个空闲位置
} StaticLinkedList;


#endif


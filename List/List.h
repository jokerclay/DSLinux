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
#define LinkedInitSize  50
typedef struct
{
    LinkedElemetType *data;
    int length;
    int maxsize;
} LinkedList;

void linkedInitList();
void linkedLength();
void linkedLocateElem();
void linkedGetElem();
void linkedListInsert();
void linkedListDelete();
void linkedPrintList();
void linkedEmpty();
void linkedDestroyList();

#endif

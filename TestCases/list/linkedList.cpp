#include <string>

#include "../../Log/log.h"
#include "../../List/List.h"


int main()
{
    LinkedList L;
    linkedInitList(L);
    int linkedListLength = linkedLength(L);
    Log(INFO,"linkedListLength is " + std::to_string(linkedListLength));
    /*LNode* target = linkedLocateElem(L,1);*/

    Log(INFO,"linked list:");
    linkedPrintList(L);
    linkedListInsert(L, 1, 69);
    linkedListInsert(L, 2, 34);
    linkedListInsert(L, 3, 35);
    linkedListInsert(L, 4, 10);
    linkedListInsert(L, 3, 89);

    Log(INFO,"linked list");
    linkedPrintList(L);

    LinkedElementType removedData = 0;
    if(linkedListDelete(L, 1,removedData))
    {
        Log(INFO,"removed data: " + std::to_string(removedData)) ;
    }else {
        Log(INFO,"removed data at " + std::to_string(1) + " Failed" );
    }

    Log(INFO,"linked list");
    linkedPrintList(L);
    if(linkedEmpty(L))
    {
        Log(ERROR,"linked list is empty " );
    }else {
        Log(INFO,"linked list is NOT empty " );
        Log(INFO,"linked list");
        linkedPrintList(L);
    }

    Log(INFO,"linked list");
    linkedPrintList(L);

    Log(INFO,"destroying linked list");
    linkedDestroyList(L);

    Log(INFO,"linked list");
    linkedPrintList(L);

    return 0;
}

#include <string>

#include "../../Log/log.h"
#include "../../List/List.h"


int main()
{
    // init
    SqList L;
    squenceInitList(L);
    int len = squenceLength(L);

    // insert
    squenceListInsert(L, 1, 69);
    squenceListInsert(L, 2, 2);
    squenceListInsert(L, 3, 23);
    squenceListInsert(L, 4, 34);
    squenceListInsert(L, 5, 82);

    // print
    Log(INFO,"squenceList");
    squencePrintList(L);


    // get position
    int elementIndex = squenceLocateElem(L, 69);
    if(elementIndex == -1)
        Log(ERROR,"Did not find this Element");
    else 
        Log(INFO,"Find Element "+ std::to_string(69)+ " at position " + std::to_string(elementIndex));



    // get element
    SqElemetType resData;
    bool res = squenceGetElem(L, 3 , resData);
    if(res)
        Log(INFO,"Get  Element at position  "+ std::to_string(3)+ " is " + std::to_string(resData));
    else
        Log(ERROR,"Could not get Element at position " + std::to_string(3));


    // isEmpty
    if(squenceEmpty(L))
        Log(INFO,"This squence is Empty");
    else
        Log(INFO,"This squence is NOT Empty");


    // remove element
    SqElemetType removedElem5;
    if(squenceListDelete(L,5,removedElem5))
        Log(INFO,"Rmoved element " + std::to_string(removedElem5) + " at position " + std::to_string(5));
    else
        Log(INFO,"Rmove element at position " + std::to_string(5) + "Failed");


    Log(INFO,"squenceList");
    squencePrintList(L);


    SqElemetType removedElem3;
    if(squenceListDelete(L,3,removedElem3))
        Log(INFO,"Rmoved element " + std::to_string(removedElem3) + " at position " + std::to_string(3));
    else
        Log(INFO,"Rmove element at position " + std::to_string(3) + "Failed");

    Log(INFO,"squenceList");
    squencePrintList(L);

    return 0;
}

#include "../../Tree/BinaryTree.h"
#include <cstdio>


int main()
{
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(values) / sizeof(values[0]);

    BiTree root = NULL;

    // orignal data
    printf("orignal data:\t");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ",values[i]);
    }
    printf("\n");

    // constract bi-tree with data
    for (int i = 0; i < n; ++i)
    {
        root = InsertNode(root, values[i]);
    }


    // pre-order
    printf("pre-order:\t");
    PreOrder(root);
    printf("\n");


    // in-order
    printf("in-order:\t");
    InOrder(root);
    printf("\n");


    // post-order
    printf("post-order:\t");
    PostOrder(root);
    printf("\n");

    IterateBinaryTreeByLevel(root);

    PrintTree(root, 0);
    FreeTree(root);
}




#include "main.h"
#include "Tree/BinaryTree.h"
#include <cstdio>
#include "DSLog/DSLog.h"

int main()
{
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(values) / sizeof(values[0]);

    BiTree root = NULL;

    // original data
    printf("original data:\t");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ",values[i]);
    }
    printf("\n");

    // construct bi-tree with data
    for (int i = 0; i < n; ++i)
    {
        root = InsertNode(root, values[i]);
        if (root == NULL) {
            LOG_ERROR_F("Failed to insert value %d into binary tree", values[i]);
            return 1;
        }
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

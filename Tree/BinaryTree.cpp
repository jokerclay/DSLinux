#include "BinaryTree.h"
#include <cstdio>
#include <cstdlib>
#include <stdint.h>

#include "../Queue/Queue.h" 

BiNode* CreateNode(BITREEDATATYPE  value)
{
    BiNode* new_node = (BiNode*)malloc(sizeof(BiNode));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed in CreateNode\n");
        return NULL;
    }
    new_node->data = value;
    new_node->lchild = new_node->rchild = NULL;
    return new_node;
}


BiNode* InsertNode(BiTree  root,BITREEDATATYPE value)
{
    if(root ==NULL) {
        BiNode* new_node = CreateNode(value);
        if (new_node == NULL) {
            printf("Error: Failed to create node in InsertNode\n");
            return NULL;
        }
        return new_node;
    }

    if(value < root->data)
        root->lchild = InsertNode(root->lchild, value);
    else if (value > root->data)
        root->rchild = InsertNode(root->rchild, value);

    return root;
}


void PreOrder(BiTree root)
{
    if(root)
    {
        printf("%d ", root->data);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }

}

void InOrder(BiTree root)
{
    if(root)
    {
        InOrder(root->lchild);
        printf("%d ", root->data);
        InOrder(root->rchild);
    }
}



void PostOrder(BiTree root)
{
    if(root)
    {
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        printf("%d ", root->data);
    }

}

void FreeTree(BiTree root)
{
    if(root)
    {
        FreeTree(root->lchild);
        FreeTree(root->rchild);
        free(root);
    }
}


void PrintTree(BiTree root, int space) {
    const int indent = 5;
    if (root == NULL)
        return;

    PrintTree(root->rchild, space + indent);
    printf("%*s%d\n", space, "", root->data);
    PrintTree(root->lchild, space + indent);
}


/*

1. 首先将根结点入队
2. 若队列非空,则队头结点出队, 访问该结点, 若它有左孩子，则将其左孩子入队
    若它有右孩子，则将其右孩子入队
3. 重复步骤 2 直至队列为空
*/

void IterateBinaryTreeByLevel(BiTree root)
{
    if (root == NULL)
        return;

    sqQueue Q;
    sqQueueInitQueue(Q);

    // We enqueue node addresses, so cast the pointer to int
    sqQueueEnQueue(Q, (sqQueueElementType)(intptr_t)root);

    printf("level-order:\t");

    while (!sqQueueQueueEmpty(Q))
    {
        BiNode* current;
        sqQueueElementType e;
        sqQueueDeQueue(Q, e);
        current = (BiNode*)(intptr_t)e;

        printf("%d ", current->data);

        if (current->lchild)
            sqQueueEnQueue(Q, (sqQueueElementType)(intptr_t)(current->lchild));

        if (current->rchild)
            sqQueueEnQueue(Q, (sqQueueElementType)(intptr_t)(current->rchild));
    }

    printf("\n");

}

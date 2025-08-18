#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum 
{
    NODE_RED,
    NODE_BLACK
}NodeColor;

typedef struct RBNode RBNode;

typedef struct RBNode
{
    int key;
    RBNode *parent;
    RBNode *left;
    RBNode *right;
    NodeColor color;
}RBNode;


int main()
{

    RBNode left = {
        .key = 8,
        .parent = NULL,
        .left = NULL,
        .right = NULL,
        .color = NODE_RED
    };

    RBNode right = {
        .key = 17,
        .parent = NULL,
        .left = NULL,
        .right = NULL,
        .color = NODE_RED
    };


    RBNode root = {
        .key = 13,
        .parent = NULL,
        .left = &left,
        .right = &right,
        .color = NODE_BLACK
    };

    printf("root.right->key : %d\n", root.right->key);

    return EXIT_SUCCESS;
}

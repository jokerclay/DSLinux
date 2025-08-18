#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#define CHANGETOBINODE


/*

5.1 树的基本概念
5.1.1 树的定义
        有且只有一个根节点
        叶子节点互不相交
        子树又是一颗树

5.1.2 树的基本术语
        1. 祖先，子孙，双亲，孩子，兄弟
        2. 层次：从上到 下 base 1
           深度：节点所在的层次就是节点的深度
           树的高度：树中节点最大的深度
        3. 节点的度：节点的孩子数
           树的度  ：树中最大的度
        4. 分支节点：分支, 还有孩子
           叶子节点：叶子, 没有孩子
        5. 有序树：节点不可以互换
           无序树：节点可以互换
        6. 路径：一个节点到另一个节点
           路径长度：一个节点到另一个节点的边
        7. 森林：多个树组成森林

5.1.3 树的性质
        1. 树的结点数 = 所有结点的度 之和  + 1
        2. 度为 `m` 的树中第 `i` 层上至多有 `m^{i-1}`
        3. 高度为 `h`的 `m` 叉树, 至多有 `(m^{h}-1)(m-1)` 个结点
        4. 度为 `m` 具有 `n` 个结点的树最小高度 h 为 `[log_{m}(n(m-1)+1)]`
        5. 度为 `m`，具有 `n` 个结点的树的最大高度 h 为 `n-m+1`

5.2 二叉树的概念
5.2.1 二叉树的定义及特征
        1. 二叉树的定义
            (1. 每个结点最多有两个结点
            (2. 不能为空
            (3. 确定左右次序

        2. 几种特殊的二叉树
            (1. 满二叉树:除了 叶子结点，每个结点的度都是 2，高度为 `h`, 有 `2^{h}+1` 个结点
                满二叉树:base on 1, top2bottom, left2right, 对于结点 i, 双亲`floor(i/2)`, 左孩子 `2i`, 右孩子 `2i + 1`
            (2. 完全二叉树:base on 1, top2bottom, left2right, 序号与满二叉树对应
            (3. 二叉排序树: 结点的值大小关系总是 ， 左 < 根 < 右
            (4. 平衡二叉树: 任意 左子树 右子树 高度差不超过 1
            (5. 正则二叉树: 树中每个分支结点都有两个孩子，即树中只有度为 0 或 2 的结点

        3. 二叉树性质
            1. 非空二叉树上叶子结点数(无孩子的结点) 等于度为 2 的结点数 加 1
            2. 非空二叉树 第 `k` 层，最多有 $2^{k-1}$ 个结点($k \geq 1$)
            3. 高度为 `h` 的二叉树 至多有 $2^{h}-1$ 个结点

        4. 对完全二叉树从上到下，从左到右, 顺序依次编号1，2，3，4，.... n 有以下关系
            1. 最后一个分支结点的编号为 floor(n/2), 若 i \leq floor(n/2), 则结点为分支结点，否则为叶子结点
            2. 子结点只可能在最后两层出现
            3. 若有度为 1 的结点，则最多只可能有一个,且该节点只有左孩子,没有右孩子
            4. 按层编号后，一旦出现某结点（如编aa号 i ）为叶子节点,或只有左孩子的情况,则编号大于 i 的结点均为 叶子结点
            5. 若 n 为奇数,则每个分支节点都有左，右孩子
               若 n 为偶数,则编号最大的分支节点(编号为 floor(n/2)), 只有 左孩子，没有右孩子, 其余分支结点都有左右孩子
            6. 当 i > 1 时,结点 i 的双亲结点的编号为 floor(i/2)
            7. 若结点 i 有左右孩子, 则左孩子编号为 2i， 右孩子编号为 2i + 1
            8. 结点 i 所在层次 (深度) 为 h = floor(log^(n)_2) + 1

        5. 具有 n 个 (n > 0 ) 结点的完全二叉树的高度为 floor(log^(n+1)_2) 或 floor(log^(n)_2) + 1


5.3 二叉树的遍历和线索二叉树
5.3.1 二叉树的遍历

        1. 前序遍历
        2. 中序遍历
        3. 后序遍历

        采用递归的方式进行二叉树的遍历不够高效, 故而引出线索二叉树, 使其更高效的遍历二叉树

5.3.2 线索二叉树

 
 */
 

#define BITREEDATATYPE int

typedef struct BiNode
{
    BITREEDATATYPE data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

BiNode* CreateNode              (BITREEDATATYPE value);
BiNode* InsertNode              (BiTree root,BITREEDATATYPE value);
void    InOrder                 (BiTree root);
void    PreOrder                (BiTree root);
void    PostOrder               (BiTree root);
void    IterateBinaryTreeByLevel(BiTree root);
void    FreeTree                (BiTree root);
void    PrintTree               (BiTree root, int space);


#endif // _BINARYTREE_H

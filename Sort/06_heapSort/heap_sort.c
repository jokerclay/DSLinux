#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#define N 8

void GenerateRandomIntTo(int *data, int n, int max, int min)
{
    for(int i =0;i < n; i++)
    {
        data[i] = rand() % (max - min + 1) + min;
    }
}


void PrintInt(int *data, int len)
{
    for (int i =0; i < len; i++) {
        printf("%d ",data[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void head_adjust(int *data,int start, int end)
{
    int root = start;
    while (1) {
        int left = 2 * root + 1;   // 左孩子索引
        int right = left + 1;      // 右孩子索引
        int largest = root;        // 假设当前 root 最大

        if (left <= end && data[left] > data[largest])
            largest = left;
        if (right <= end && data[right] > data[largest])
            largest = right;

        if (largest != root) {
            int tmp = data[root];
            data[root] = data[largest];
            data[largest] = tmp;
            root = largest; // 继续下滤
        } else {
            break; // 堆性质已满足
        }
    }
}

void build_heap(int *data, int len)
{
    // `len/2` 所有的非终端结点的编号
    for (int i = (len/2)-1; i>=0; i--) {
        printf("-> 非终端结点【%d】: %d\n",i,data[i]);
        head_adjust(data, i,len-1);
    }

}

void heap_sort(int *data,int n)
{
    // 建立大根堆
    build_heap(data, n);

    // 基于大根堆进行排序

}



int main()
{
    srand(time(NULL));
    int data[N] = {53,17,78,9,45,65,87,32};
    /*GenerateRandomIntTo(data, N,  99, 0); */

    printf("[Before Quick Sorting...]\n");
    PrintInt(data,N);

    heap_sort(data,N);

    printf("[After Quick Sorting...]\n");
    PrintInt(data,N);
}


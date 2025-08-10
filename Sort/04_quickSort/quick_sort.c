#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#define N 100

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

int Partion(int *data, int low, int high)
{
    int pivot = data[low];
    while (low < high) {

        while (low<high &&data[high] >= pivot) {
            --high;
        }

        data[low] = data[high];

        while (low<high &&data[low] <= pivot) {
            ++low;
        }

        data[high] = data[low];
    }

    data[low] = pivot;
    return low;

}


void quick_sort(int *data, int low, int high) {
    if(low < high)
    {
        int pivot_pos = Partion(data, low,high);
        quick_sort(data, low, pivot_pos-1);
        quick_sort(data,  pivot_pos+1,high);
    }
}



int main()
{
    srand(time(NULL));
    int data[N] = {0};
     GenerateRandomIntTo(data, N,  99, 0); 

    printf("[Before Quick Sorting...]\n");
    PrintInt(data,N);

    quick_sort(data,0,N-1);

    printf("[After Quick Sorting...]\n");
    PrintInt(data,N);
}

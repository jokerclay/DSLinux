#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#define N 5

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


void bubble_sort(int *data, int n) {
    for (int i = 0; i < n-1; i++) {
        bool flag = false;
        for(int j = n-1; j > i;j--)
        {
            if(data[j-1]>data[j])
            {
                swap(&data[j - 1], &data[j]);
                flag = true;
            }
        }
        if(!flag)
            return;
    }
}



int main()
{
    srand(time(NULL));
    int data[N] = {5,4,3,2,1};
    /*GenerateRandomIntTo(data, N,  99, 10);*/

    printf("[Before Shell Sorting...]\n");
    PrintInt(data,N);

    bubble_sort(data,N);

    printf("[After  Sorting...]\n");
    PrintInt(data,N);
}

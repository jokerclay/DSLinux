#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#define N 10

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

void select_sort(int *data,int n)
{
    for (int i = 0; i < n; i++) {
        int min = i;
        for(int j = i+1;j<n;j++)
        {
            if (data[j] < data[min]) {
                min = j;
            }
        }
        if(min != i) swap(&data[i], &data[min]);
    }
}


int main()
{
    srand(time(NULL));
    int data[N] = {0};
    GenerateRandomIntTo(data, N,  99, 0); 

    printf("[Before Quick Sorting...]\n");
    PrintInt(data,N);

    select_sort(data,N);

    printf("[After Quick Sorting...]\n");
    PrintInt(data,N);
}


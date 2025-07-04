#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerateRandomIntTo(int *data, int n, int max, int min)
{
    srand(time(NULL));
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



void InsertSort(int* data,int n)
{
    for(int i = 1; i < n;i++)
    {
        int j = i -1;
        int key = data[i];
        while (j >=0 && data[j] > key) {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
    }

}

int main()
{
    int n = 10;
    int data[n] = {};
    GenerateRandomIntTo(data, n,  99, 10);

    printf("[Before Sorting]\n");
    PrintInt(data,n);

    InsertSort(data,n);

    printf("[After Sorting]\n");
    PrintInt(data,n);
}



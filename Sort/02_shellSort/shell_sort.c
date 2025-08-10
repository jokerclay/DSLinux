#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

/**/
/*void shell_sort(int *data, int n )*/
/*{*/
/*    int distance, i, j;*/
/*    for(distance = n/2; distance>=1;distance=distance/2)*/
/*    {*/
/*        for (i  = distance + 1 ; i <=n; ++i) {*/
/*            if(data[i] < data[i-distance])*/
/*            {*/
/*                data[0] = data[i];*/
/*                for (j = i-distance; j>0 && data[0] < data[i]; j-=distance) {*/
/*                    data[j+distance] = data[j];*/
/*                }*/
/*                data[j+distance] = data[0];*/
/*            }*/
/**/
/*        }*/
/*    }*/
/*}*/


void shell_sort(int *data, int n) {
    int distance, i, j, temp;
    for (distance = n / 2; distance > 0; distance /= 2) {
        for (i = distance; i < n; ++i) {
            temp = data[i];
            for (j = i; j >= distance && temp < data[j - distance]; j -= distance) {
                data[j] = data[j - distance];
            }
            data[j] = temp;
        }
    }
}


int main()
{
    srand(time(NULL));
    int data[N] = {5,4,3,2,1};
    /*GenerateRandomIntTo(data, N,  99, 10);*/

    printf("[Before Shell Sorting...]\n");
    PrintInt(data,N);

    shell_sort(data,N);

    printf("[After  Sorting...]\n");
    PrintInt(data,N);
}

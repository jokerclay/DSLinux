#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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


// wang dao 408
/*
 * Insertion Sort (ascending order)
 *
 * Algorithm:
 * 1. Treat the first element as a sorted subarray.
 * 2. For each remaining element:
 *    - Store the current element.
 *    - Shift all larger elements in the sorted subarray one position to the right.
 *    - Insert the stored element into its correct sorted position.
 * 3. Repeat until the array is fully sorted.
 *
 * Time Complexity:
 *   Best case:  O(n)   (already sorted)
 *   Worst case: O(n^2) (reverse order)
 * Space Complexity: O(1) (in-place)
 */
void InsertSort2(int *data,int n)
{
    int i, j, temp;

    for(int i =1;i < n;i++)
    {
        int current = data[i];
        int prev = data[i-1];

        if(current < prev)
        {
            temp = current; // Store the value to insert

            // Shift elements in the sorted portion (indices 0..i-1) to the right
            // until the correct position for 'temp' is found.
            for(j = i-1; j>=0 && data[j] > temp; --j)
            {
                data[j+1] = data[j]; // ordered right shift
            }

            // Insert 'temp' into its sorted position
            data[j+1] = temp;
        }
    }
}

int main()
{

    srand(time(NULL));

    int data[N] = {};
    GenerateRandomIntTo(data, N,  99, 10);

    printf("[Before Sorting...]\n");
    PrintInt(data,N);

    InsertSort2(data,N);

    printf("[After Sorting...]\n");
    PrintInt(data,N);

    printf("[Regenerating numbers...]\n");
    GenerateRandomIntTo(data, N,  99, 10);

    printf("[Before Sorting...]\n");
    PrintInt(data,N);

    InsertSort2(data,N);

    printf("[After Sorting...]\n");
    PrintInt(data,N);


    printf("[Regenerating numbers...]\n");
    GenerateRandomIntTo(data, N,  99, 10);

    printf("[Before Sorting...]\n");
    PrintInt(data,N);

    printf("[After Sorting With Sentry...]\n");
    PrintInt(data,N);
}

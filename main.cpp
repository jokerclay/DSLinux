#include "main.h"
#include "DSLog/DSLog.h"
#include "Array/Array.h"

int main()
{

/*
1 2 3
4 5 6
7 8 9
*/

    int column =3;
    int row =3;
    int array_size = 9;
    int rowFirst[] = {1,2,3, 4, 5, 6,7, 8, 9};  // 行优先
    int columnFist[] = {1,4,7, 2, 5, 8,3, 6, 9};// 列优先

    demostrateColumnFirstArray(columnFist,row,column,array_size);
    demostrateRowFirstArray(rowFirst,row,column,array_size);

// 对称矩阵

/*

1 2 3
2 1 6
3 6 1

*/
    int symmetricArray[] = {1,2,1,3,6,1};
    demonstrateSymmetricPackedMatrix(symmetricArray, 3);


// 稀疏矩阵

/*

4 0  0 0 
0 0  6 0
0 9  0 0
0 23 0 0

 |||
  V

i j a_{ij}
0 0 4
1 2 6
2 1 9
3 1 23

*/

    int sparseMatrix[] = {
        4,  0,  0,  0,
        0,  0,  6,  0,
        0,  9,  0,  0,
        0, 23,  0,  0
    };

    demonstrateSparseMatrix(sparseMatrix, 4, 4);

    return 0;
}

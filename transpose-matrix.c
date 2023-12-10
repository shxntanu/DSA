/**

Link: https://leetcode.com/problems/transpose-matrix/

 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().

Test Case: 

Input:
matrix = [[1,2,3],[4,5,6],[7,8,9]]

Output:
matrix = [[1,4,7],[2,5,8],[3,6,9]]
 */

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {

    // Checking for empty matrix
    if(matrixSize == 0 || *matrixColSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Transposed Matrix Dimensions
    int rowSize = *matrixColSize;
    int colSize = matrixSize;
    int** transposedMatrix = (int**)malloc(rowSize * sizeof(int*));    // Malloc a double pointer to a memory loc with size = Number of rows
    *returnColumnSizes = (int*)malloc(rowSize * sizeof(int));          // Malloc a pointer to a memory loc with size = number of rows

    // Creating the transpose matrix
    for(int i=0; i<rowSize; i++) {
        transposedMatrix[i] = (int*)malloc(colSize * sizeof(int));      // For every row element, allocate a column of "colSize" elements
        (*returnColumnSizes)[i] = colSize;                              // Mark column size in returnColumnSizes array
    }

    // Filling the matrix
    for(int i=0;i<matrixSize;i++) {
        for(int j=0;j<*matrixColSize;j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    *returnSize = rowSize;
    return transposedMatrix;
}

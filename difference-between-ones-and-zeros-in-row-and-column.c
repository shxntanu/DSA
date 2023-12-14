/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().

 Link: https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column
 */

int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int* onesRow = (int*)calloc(gridSize,sizeof(int));
    int* onesCol = (int*)calloc(gridColSize[0],sizeof(int));
    int** returnMatrix = (int**)malloc(gridSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(gridSize * sizeof(int));    

    for(int row = 0;row<gridSize;row++) {
        returnMatrix[row] = (int*)malloc(gridColSize[0] * sizeof(int));
        for(int col = 0;col<gridColSize[0];col++) {
            if(grid[row][col] == 1) {
                onesRow[row]++;
                onesCol[col]++;
            } else {
                onesRow[row]--;
                onesCol[col]--;
            }
        }
        (*returnColumnSizes)[row] = gridColSize[0];
    }

    for(int row = 0;row<gridSize;row++) {
        for(int col = 0;col<gridColSize[0];col++) {
            returnMatrix[row][col] = onesRow[row] + onesCol[col];
        }
    }

    *returnSize = gridSize;
    return returnMatrix;
}

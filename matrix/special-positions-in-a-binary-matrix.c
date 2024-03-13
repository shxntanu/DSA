#include <stdlib.h>

int numSpecial(int** mat, int matSize, int* matColSize) {
    int result = 0;
    int* rowSums = (int*)malloc(matSize * sizeof(int));
    int* colSums = (int*)malloc(matColSize[0] * sizeof(int));
    for (int i = 0; i < matSize; i++) {
        rowSums[i] = 0;
    }
    for (int j = 0; j < matColSize[0]; j++) {
        colSums[j] = 0;
    }
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[0]; j++) {
            rowSums[i] += mat[i][j];
            colSums[j] += mat[i][j];
        }
    }
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[0]; j++) {
            if (mat[i][j] == 1 && rowSums[i] == 1 && colSums[j] == 1) {
                result++;
            }
        }
    }
    free(rowSums);
    free(colSums);

    return result;
}

int max(int a, int b) {
    return a>b?a:b;
}

int compare(const void* a, const void* b) {
    return ( *(int*)a - *(int*)b);
}

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize) {
    int* X = (int*)malloc(pointsSize * sizeof(int));
    for(int i=0;i<pointsSize;i++) X[i] = points[i][0];
    qsort(X, pointsSize, sizeof(int), compare);
    int diff = 0;
    for(int i=1;i<pointsSize;i++) {
        if((X[i] - X[i-1]) > diff) diff = X[i] - X[i-1];
    }
    free(X);
    return diff;
}

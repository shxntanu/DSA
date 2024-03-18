int compare (const void** p1, const void** p2) {
    int* arr1 = *(int**) p1;
	int* arr2 = *(int**) p2;
    if(arr1[1] ==arr2[1]) return 0;
    else if(arr1[1] >arr2[1]) return 1;
    else return -1;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    qsort(points, pointsSize, sizeof(int*), compare);
    int count = 1, x = points[0][1];
    for(int i=1;i<pointsSize;i++) {
        if(points[i][0] > x) {
            x = points[i][1];
            count++;
        }
    }
    return count;
}

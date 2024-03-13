/*
  0ms Runtime, 7.14mb Memory
*/

int pivotInteger(int n) {
    int *leftSum = (int*)calloc(n, sizeof(int));
    int *rightSum = (int*)calloc(n, sizeof(int));
    leftSum[0] = 1;
    rightSum[n-1] = n;
    for(int i=1;i<n;i++) leftSum[i] = leftSum[i-1] + i + 1;
    for(int j=n-1; j>0; j--) rightSum[j-1] = rightSum[j] + j; 
    for(int i=0; i<n; i++) if(leftSum[i] == rightSum[i]) return i+1;
    return -1;
}

/*
  3ms Runtime, 5.44mb Memory
*/
int pivotInteger(int n) {
    for (int i=1; i<=n; i++){
        int leftsum = (i * (i+1) / 2);
        int rightsum = (n * (n+1) / 2) - leftsum + i;
        if (leftsum == rightsum) return i;
    } return -1;
}

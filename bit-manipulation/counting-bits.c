int* countBits(int n, int* returnSize) {
    int* ans = (int*)malloc((n+1) * sizeof(int));
    ans[0] = 0;
    for(int i=1; i<=n; i++)
        ans[i] = ans[i/2] + i%2;
    *returnSize = n + 1;
    return ans;
}

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    int *dp = (int*)malloc(n * sizeof(int));
    for(int i=0;i<n;i++) dp[i] = INT_MAX;
    dp[src] = 0;

    for(int i=0; i<=k; i++) {
        int *temp = (int*)malloc(n * sizeof(int));
        memcpy(temp, dp, n * sizeof(int));
        for(int f=0; f<flightsSize; f++) {
            int *flight = flights[f];
            if(dp[flight[0]] != INT_MAX) {
                temp[flight[1]] = (temp[flight[1]] < (dp[flight[0]] + flight[2])) ? temp[flight[1]] : (dp[flight[0]] + flight[2]);
            }
        }
        free(dp);
        dp = temp;
    }
    int res = dp[dst] == INT_MAX ? -1 : dp[dst];
    free(dp);
    return res;
}

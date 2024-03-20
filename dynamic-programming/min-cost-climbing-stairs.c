int minCostClimbingStairs(int* cost, int n) {
    for(int i=2; i<n;i++) cost[i] += fmin(cost[i-1], cost[i-2]);
    return fmin(cost[n-1], cost[n-2]);
}

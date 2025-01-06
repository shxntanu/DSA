int* minOperations(char* boxes, int* returnSize) {
    int n = strlen(boxes);
    int *res = (int*)calloc(n,sizeof(int));

    // Move balls from left to right
    for(int i=0, ballcounter = 0, operations = 0; i < n; i++) {
        res[i] += operations;
      
        // Count the number of balls encountered so far
        ballcounter += boxes[i] == '1' ? 1 : 0;
      
        // Cost of moving balls to the i'th position is equal to
        // cost[i] = cost[i - 1] + (1 * currentBalls) where 1 here is the cost of moving a single ball.
        // where cost[i-1] is moving existing balls to the previous position
        operations += ballcounter;
    }

    // Move balls from right to left
    for(int i=n-1, ballcounter = 0, operations = 0; i >= 0; i--) {
        res[i] += operations;
        ballcounter += boxes[i] == '1' ? 1 : 0;
        operations += ballcounter;
    }

    *returnSize = n;
    return res;
}

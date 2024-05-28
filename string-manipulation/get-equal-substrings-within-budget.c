#define MAX(a,b) (((a)>(b))?(a):(b))
int equalSubstring(char* s, char* t, int maxCost) {
    int n = strlen(s);
    int *cost = (int*)malloc(n * sizeof(int));
    for(int i=0; i<n;i++) 
        cost[i] = abs(s[i] - t[i]);
    int start = 0, end = 0, currentSum = 0, maxLength = 0;
    while(end < n) {
        currentSum += cost[end];
        while(currentSum > maxCost && start <= end) 
            currentSum -= cost[start++];
        maxLength = MAX(end - start + 1, maxLength);
        end++;
    }
    return maxLength;
}

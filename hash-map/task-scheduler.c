int compare(const void* a, const void* b){
    return *(int*)b - *(int*)a;
}

int leastInterval(char* tasks, int tasksSize, int n){
    int* count = calloc(26, sizeof(int));
    for(int i = 0; i < tasksSize; i++) count[tasks[i] - 'A']++;
    qsort(count, 26, sizeof(int), compare);
    int max_cn = 1;
    for(int i = 1; i < 26; i++){
        if(count[i] == count[0])
            max_cn++;
        else 
            break;
    }
    
    int ans = (count[0] - 1) * (n+1) + max_cn;
    ans = fmax(ans, tasksSize) ;
    return ans;
}

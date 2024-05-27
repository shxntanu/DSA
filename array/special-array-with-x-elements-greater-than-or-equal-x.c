int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int specialArray(int* nums, int n) {
    qsort(nums, n, sizeof(int), compare);
    for(int i=0; i<n; i++) {
        if(nums[i] >= (n-i)) {
            if(i==0) return n-i;
            else{
                if(nums[i-1] < (n-i))
                    return (n-i) ;
            }
        }
    }
    return -1;
}

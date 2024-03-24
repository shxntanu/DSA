int findDuplicate(int* nums, int numsSize) {
    int *arr=(int *)calloc(numsSize,sizeof(int));
    for(int i=0;i<numsSize;i++){
        int index=nums[i];
        if(arr[index-1]){
            return index;
        }
        arr[index-1]=index;
    }
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    *returnSize = candiesSize;
    bool* result = (bool*)malloc(candiesSize * sizeof(bool));
  
    // mv_we: Max value without extra
    int mv_we = candies[0];
    for(int i=0;i<candiesSize;i++) {
        if(candies[i] >= mv_we) 
            mv_we = candies[i];
    }
    for(int i=0;i<candiesSize;i++) {
        if(candies[i] + extraCandies >= mv_we)
            result[i] = true;
        else result[i] = false;
    }
    return result;
}

int maxFrequencyElements(int* nums, int numsSize) {
    int map[101] = {0}, max = 0, count = 0;
    while(numsSize--) map[*nums++]++;
    for(int i=0; i<101;i++) {
        if(map[i] == max) count += map[i];
        else if(map[i] > max) {
            max = map[i];
            count = map[i];
        }
    }
    return count;
}

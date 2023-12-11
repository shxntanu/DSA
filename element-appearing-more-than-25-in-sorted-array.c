/*
Link: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array
*/

int findSpecialInteger(int* arr, int arrSize) {
    int curr =0, count = 0;
    int size = 1 + (arrSize/4);
    for(int i=0;i<arrSize;i++) {
        if(arr[i] != curr) {
            if(count >= size) {
                return curr;
            } else {
                curr = arr[i];
                count = 1;
                continue;
            }
        } else {
            count++;
        }
    }
    return curr;
}

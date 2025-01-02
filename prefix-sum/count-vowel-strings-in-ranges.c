int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int *prefixSum = (int*)calloc((wordsSize + 1), sizeof(int));
    char *vowels = "aeiou";
    prefixSum[0] = 0;
  
    for (int i = 0; i < wordsSize; i++) {
        prefixSum[i + 1] = prefixSum[i];
        if (strchr(vowels, words[i][0]) && strchr(vowels, words[i][strlen(words[i]) - 1])) {
            prefixSum[i + 1]++;
        }
    }

    int *ans = (int*)malloc(queriesSize * sizeof(int));
    for(int i=0; i<queriesSize; i++) {
        ans[i] = prefixSum[queries[i][1]+1] - prefixSum[queries[i][0]];
    }
    *returnSize = queriesSize;
    free(prefixSum);
    return ans;
}

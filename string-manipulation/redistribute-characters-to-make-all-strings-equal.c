bool makeEqual(char** words, int wordsSize) {
    int* hash = (int*)calloc(26,sizeof(int));
    for(int i = 0; i<wordsSize; i++) {
        int j=0;
        while(words[i][j] != '\0') {
            hash[(int)(words[i][j]) - 97]++;
            j++;
        }
    }
    for(int i = 0; i<26; i++) {
        if(hash[i] % wordsSize != 0) {free(hash); return false;}
    } 
    free(hash);
    return true;
}

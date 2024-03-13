char* firstPalindrome(char** words, int wordsSize) {
    for(int i=0;i<wordsSize; i++) {
        int l=0, h = strlen(words[i]) - 1; int flag = 1;
        while(h>l) {
            if(words[i][l++] != words[i][h--]) { flag = false; break; }
        }
        if(flag) {return words[i]; return 0;}
    }
    char *a = "";
    return a;
}

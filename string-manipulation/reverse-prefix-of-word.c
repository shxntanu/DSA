char* reversePrefix(char* word, char ch) {
    int n = strlen(word);
    int loc = -1;
    for(int i = 0; i < n; i++){
        if(word[i] == ch){
            loc = i;
            break;
        }
    }

    if(loc == -1) return word;
    for(int i=0; i<=loc/2; i++) {
        char temp = word[i];
        word[i] = word[loc-i];
        word[loc-i] = temp;
    }
    return word;
}

char* maximumOddBinaryNumber(char* s){
    int n = strlen(s);
    int oneCnt = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == '1') {
            oneCnt++;
            s[i] = '0';
        }
    }
    int i = 0;
    for(i=0;i<oneCnt-1;i++) s[i] = '1';
    for(; i<n-1;i++) s[i] = '0';
    s[i] = '1';
    return s;
}

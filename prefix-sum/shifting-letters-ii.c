char* shiftingLetters(char* s, int** shifts, int shiftsSize, int* shiftsColSize) {
    int n = strlen(s);
    int diff[n + 1];
    memset(diff, 0, sizeof(diff));
    for(int i=0; i<shiftsSize; i++) {
        int l = shifts[i][0], r = shifts[i][1], dir = shifts[i][2];
        diff[l] += (dir == 1 ? 1 : -1);
        if(r + 1 < n) diff[r + 1] -= (dir == 1 ? 1 : -1);
    }

    int currentShift = 0;
    for(int i=0; i<n; i++) {
        currentShift += diff[i];
        diff[i] = currentShift;
    }

    for(int i=0; i<n; i++) {
        // This is done to prevent negative shifts
        int netShift = (diff[i] % 26 + 26) % 26;
        s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
    }

    return s;
}

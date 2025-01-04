int countPalindromicSubsequence(char *s) {
	int n = strlen( s ), i, ans = 0;
	int alpha[26][2], j;
	
	for (i = 0; i < 26; i++) {
        alpha[i][0] = -1;
        alpha[i][1] = -1;
    }
		
	for (i = 0; i < n; i++) {
		int pos = s[i] - 'a';
        // First Occurrence
		if (alpha[pos][0] == -1)
			alpha[pos][0] = i;
        // Next Occurrence
		else
			alpha[pos][1] = i;
	}
	
	for ( i = 0; i < 26; i++) {
		if (alpha[i][1] != -1) {
			bool hash[26] = {false};
			for (j = alpha[i][0] + 1; j < alpha[i][1]; j++) {
				if ( hash[ s[j] - 'a' ] == 0) {
					ans += 1;
					hash[ s[j] - 'a' ] = 1;
				}
            }
		}
    }
	return ans;
}

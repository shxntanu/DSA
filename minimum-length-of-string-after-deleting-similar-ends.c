int minimumLength(char* s) {
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right) {
	    if (s[left] != s[right]) return right - left + 1;
	    char c = s[left];
	    while (left <= right && c == s[left]) left += 1;
	    while (left <= right && c == s[right]) right -= 1;
    }
    return (left == right) ? (1) : (0);
}

/*
  Link: https://leetcode.com/problems/valid-anagram
*/

/int compareChars(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

bool isAnagram(char* s, char* t) {
    if(strlen(s) != strlen(t)) return false;
    char* sorted_s = strdup(s); // duplicate s
    char* sorted_t = strdup(t); // duplicate t
    qsort(sorted_s, strlen(s), sizeof(char), compareChars);
    qsort(sorted_t, strlen(t), sizeof(char), compareChars);
    bool result = strcmp(sorted_s, sorted_t) == 0;
    free(sorted_s);
    free(sorted_t);
    return result;
}

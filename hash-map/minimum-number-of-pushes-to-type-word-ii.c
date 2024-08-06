int compare(const void* a, const void* b) {
    return ( *(uint32_t*)b - *(uint32_t*)a);
}

int minimumPushes(char* word) {
    uint32_t n = strlen(word);
    uint32_t map[26] = {0};
    for(size_t i=0; i<n; i++)
        map[word[i] - 'a']++;
    qsort(map, 26, sizeof(uint32_t), compare);
    int ans = 0;
    for(size_t i=0; i<8; i++) ans += map[i];
    for(size_t i=8; i<16; i++) ans += map[i] * 2;
    for(size_t i=16; i<24; i++) ans += map[i] * 3;
    for(size_t i=24; i<26; i++) ans += map[i] * 4;
    return ans;
}

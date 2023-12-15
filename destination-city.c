char* destCity(char*** paths, int pathsSize, int* pathsColSize) {
    char *cur = paths[0][1];
    bool found = true;
    while (found){
        found = false;
        for (int i = 0; i < pathsSize; i++){
            if (strcmp(paths[i][0], cur) == 0){
                found = true;
                cur = paths[i][1];
                break;
            }
        }
    }
    return cur;
}

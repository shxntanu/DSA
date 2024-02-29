int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    int *outdeg=NULL,*indeg=NULL;
    if (!trust) return 0;
    else if (trustSize == 0 && N==1) return N;
    else if (trustSize == 0 && N!=1) return -1;
    indeg = (int*)calloc(N+1,(N+1)*sizeof(int));
    outdeg = (int*)calloc(N+1,(N+1)*sizeof(int));
    for (int i=0;i<trustSize;i++) {
        indeg[trust[i][1]]+=1;
        outdeg[trust[i][0]]+=1;
    }
    for (int i=0;i<=N;i++) {
        if (indeg[i] == N-1 && outdeg[i]==0) return i;
    }
    return -1;
}

int maxScore(char* s)
{
    int len = strlen(s);
    if (len==2) {return 1-(s[0]-48) + s[1]-48;}
    int *arr = (int*) calloc(len, sizeof(int));
    int i=0, j=len-1, l=0, r=0, k=1, max=0;
    while (i < len)
    {
        l += 1-(s[i]-48);
        r += s[j]-48;
        arr[i++] += l;
        arr[j--] += r;
    }
    while (k < len-1) {max = arr[k++]>max ? arr[k-1]:max;}
    free(arr);
    return max;
}

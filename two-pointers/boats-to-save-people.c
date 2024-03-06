int compare(const void* a, const void* b) {
    return ( *(int*)a - *(int*)b);
}

int numRescueBoats(int* people, int peopleSize, int limit) {
    qsort(people, peopleSize, sizeof(int), compare);
    int lb = 0, ub = peopleSize - 1;
    int count = 0;
    while(lb <= ub) {
        int sum = people[lb] + people[ub];
        if(sum <= limit) {
            count++;
            lb++;
            ub--;
        }
        else {
            count++;
            ub--;
        }
    }
    return count;
}

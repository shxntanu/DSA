int comp(const void**a, const void** b){
    if ((*(int**)a)[2] == (*(int**)b)[2]){
        return (*(int**)a)[0] - (*(int**)b)[0];
    }
    return (*(int**)a)[2] - (*(int**)b)[2];
}

void check(int* list, int a, int b, int i, int* returnSize, int* ans, int* time, int* timecount){
    if (list[a] - list[b] == 1){
        list[b]++;
        ans[*returnSize] = b;
        *returnSize += 1;
    } else if (list[b] - list[a] == 1){
        list[a]++;
        ans[*returnSize] = a;
        *returnSize += 1;
    } else if (list[b] == 0 && list[a] == 0){
        time[*timecount] = i;
        *timecount += 1;
    }
}

void sametime(int** meetings, int* ans, int* returnSize, int* time, int timecount, int* list){
    int count = 1;
    int newtimecount;
    while (count > 0){
        int copy = *returnSize;
        newtimecount = 0;
        for (int i = 0 ; i < timecount ; i++){
            check(list, meetings[time[i]][0], meetings[time[i]][1], time[i], returnSize, ans, time, &newtimecount);
        }
        count = *returnSize - copy;
        if (count == 0){
            break;
        }
        copy = *returnSize;
        timecount = newtimecount;
        newtimecount = 0;
        for (int i = timecount-1 ; i >= 0 ; i--){
            check(list, meetings[time[i]][0], meetings[time[i]][1], time[i], returnSize, ans, time, &newtimecount);
        }
        count = *returnSize - copy;
        timecount = newtimecount;
    }
}

int* findAllPeople(int n, int** meetings, int meetingsSize, int* meetingsColSize, int firstPerson, int* returnSize){
    int* list = calloc(n,sizeof(int));
    int* ans = malloc(sizeof(int)*n);
    int* time = malloc(sizeof(int)*n);
    int timecount = 0;
    *returnSize = 2;
    for (int i = 0 ; i < meetingsSize ; i++){
        if (meetings[i][0] > meetings[i][1]) {
            int a = meetings[i][1];
            meetings[i][1] = meetings[i][0];
            meetings[i][0] = a;
        }
    }
    qsort(meetings,meetingsSize,sizeof(int*),comp);
    list[0]++;
    list[firstPerson]++;
    ans[0] = 0;
    ans[1] = firstPerson;
    for (int i = 0 ; i < meetingsSize ; i++){
        if (list[meetings[i][0]] - list[meetings[i][1]] == 1){
            list[meetings[i][1]]++;
            ans[*returnSize] = meetings[i][1];
            *returnSize += 1;
        } else if (list[meetings[i][1]] - list[meetings[i][0]] == 1){
            list[meetings[i][0]]++;
            ans[*returnSize] = meetings[i][0];
            *returnSize += 1;
        } else if (i+1 < meetingsSize && meetings[i][2] == meetings[i+1][2]){
            timecount = 0;
            check(list, meetings[i][0], meetings[i][1], i, returnSize, ans, time, &timecount);
            i++;
            while (i+1 < meetingsSize && meetings[i][2] == meetings[i+1][2]){
                check(list, meetings[i][0], meetings[i][1], i, returnSize, ans, time, &timecount);
                i++;
            }
            check(list, meetings[i][0], meetings[i][1], i, returnSize, ans, time, &timecount);
            sametime(meetings, ans, returnSize, time, timecount, list);
        }
    }
    free(list);
    free(time);
    return ans;
}

/*
    Link: https://leetcode.com/problems/greatest-common-divisor-of-strings
*/

char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int a = len1;
    int b = len2;

    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    if (len1 < len2 && strncmp(str1, str2+ (len2 - len1), len1) != 0)
        return "";
    
    if (len1 > len2 && strncmp(str1+ (len1 - len2), str2, len1) != 0)
        return "";

    if (strncmp(str1, str2, a) != 0){
        return "";
    }

    while (len1 > (a+b)){
        a = a + b;
        if (strncmp(str1+a, str2, b) != 0){
            return "";
        }
    }

    a = b;

    if (strncmp(str1, str2, b) != 0){
        return "";
    }

    while (len2 > (b+a)){
        b = b + a;
        if (strncmp(str1, str2+b, a) != 0){
            return "";
        }
    }
    str1[a] = '\0';
    return str1;
}

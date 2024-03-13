/*
Link: https://leetcode.com/problems/reverse-vowels-of-a-string

Test Case:
Input: s = "hello"
Output: "holle"
*/

void swap(char *s, int leftIndex, int rightIndex){
    char temp = s[leftIndex];
    s[leftIndex] = s[rightIndex];
    s[rightIndex] = temp;
}

bool isVowel(char character){
    return character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' ||
        character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U';
}

char* reverseVowels(char* s) {
    int leftIndex = 0, rightIndex = strlen(s) - 1;
    while(leftIndex < rightIndex) {
        if(!isVowel(s[leftIndex])) {
            leftIndex++;
            continue;
        }
        if(!isVowel(s[rightIndex])) {
            rightIndex--;
            continue;
        }
        swap(s, leftIndex, rightIndex);
        leftIndex++;
        rightIndex--;
    }
    return s;
}

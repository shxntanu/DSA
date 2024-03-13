/*
 Link: https://leetcode.com/problems/merge-strings-alternately

 Test Case:
  Input: word1 = "abc", word2 = "pqr"
  Output: "apbqcr"
  Explanation: The merged string will be merged as so:
  word1:  a   b   c
  word2:    p   q   r
  merged: a p b q c r
*/

char * mergeAlternately(char * word1, char * word2){
    int len1 = strlen(word1), len2 = strlen(word2);
    char* result = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    int i=0,j=0,k=0;
    while( i < len1 || j < len2) {
        if(i < len1) 
            result[k++] = word1[i++];
        
        if(j < len2) 
            result[k++] = word2[j++];
    }
    result[k] = '\0';
    return result;
}

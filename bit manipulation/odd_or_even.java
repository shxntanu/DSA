
// Question : https://www.codingninjas.com/studio/problems/odd-even_7993579

class odd_or_even {
    public static String oddEven(int N) {
        int ans = N & 1;
        if (ans == 1) {
            return "odd";
        } else {
            return "even";
        }
    }
 }
 
// Explanation :
// N & 1: Perform a bitwise AND operation between N and 1. This extracts the least significant bit of N.
// ans == 1 ? "odd" : "even": If the least significant bit is 1, return "odd"; otherwise, return "even".
// The method returns a string indicating whether the given integer is odd or even.
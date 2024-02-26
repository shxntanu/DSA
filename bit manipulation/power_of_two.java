
// Question : https://leetcode.com/problems/power-of-two/

public class power_of_two {
    public boolean isPowerOfTwo(int n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n >>= 1;
        }
        return count == 1;
    }
}

// Explanation:

// count += n & 1;: Count the number of '1' bits by using bitwise AND with 1.
// n >>= 1;: Right shift n by 1, effectively moving to the next bit in the binary representation.
// Repeat steps 1 and 2 until n becomes 0.
// If count is 1, it means there was exactly one '1' bit in the binary representation, indicating a power of two. The method returns true; otherwise, it returns false.


// Question : https://leetcode.com/problems/bitwise-and-of-numbers-range/description/

public class bitwise_and_of_numbers_range {
    public int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right &= (right - 1);
        }
        return right;
    }
}
// Explanation :
// This code iterates through the range (left to right) and repeatedly clears the least significant set bit of
//  right until left and right become equal. The final value of right will be the bitwise AND of all numbers 
//  in the range. If left and right are equal initially, the loop won't execute, and the original value of 
//  right is returned.


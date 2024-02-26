
// Question : https://leetcode.com/problems/single-number/description/

public class single_number {
    public int singleNumber(int[] nums) {
        int ans = 0;
        for (int i : nums) {
            ans ^= i;
        }
        return ans;
    }
}

// Explanation :
// The method takes an array of integers (nums) as input.
// It initializes the variable ans to 0. This variable will store the result.
// It iterates through each element in the array using the enhanced for loop.
// Inside the loop, it performs the XOR (^) operation between the current value of ans and the current element i. This effectively toggles the bits of ans based on the bits of the current element.
// After the loop, ans will contain the XOR of all elements. Since XORing a number with itself results in 0, and XORing a number with 0 gives the number itself, the final value of ans will be the single number that occurs only once in the array.
// The method returns the computed result.


//  Question Link : https://www.codingninjas.com/studio/problems/bit-manipulation_8142533

public class intro_bit_manipulation {
    public static int[] bitManipulation(int num, int i) {
        int[] ans = new int[3];
        ans[0] = (num >> (i - 1)) & 1;
        ans[1] = num | (1 << (i - 1));
        ans[2] = num & ~(1 << (i - 1));

        return ans;
    }
}

// Explanation : The bitManipulation method takes two parameters: num and i. It performs three bitwise operations on num and returns the results in an array.

// ans[0] = (num >> (i - 1)) & 1;

// Right-shift num by (i - 1) positions.
// Perform bitwise AND with 1 to extract the least significant bit (LSB) after the shift.
// Store the result in ans[0].
// ans[1] = num | (1 << (i - 1));

// Left-shift 1 by (i - 1) positions to create a bitmask with a 1 at the (i - 1)-th position.
// Perform bitwise OR with num to set the bit at the (i - 1)-th position.
// Store the result in ans[1].
// ans[2] = num & ~(1 << (i - 1));

// Left-shift 1 by (i - 1) positions and complement to create a bitmask with a 0 at the (i - 1)-th position.
// Perform bitwise AND with num to clear the bit at the (i - 1)-th position.
// Store the result in ans[2].
// The returned array ans contains three elements:

// ans[0]: The value of the LSB after right-shifting.
// ans[1]: The result after setting the bit at the (i - 1)-th position.
// ans[2]: The result after clearing the bit at the (i - 1)-th position.




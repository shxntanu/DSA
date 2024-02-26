
// Question : https://www.codingninjas.com/studio/problems/count-total-set-bits_784

class count_total_set_bits {
        public static int countSetBits(int n) {
            int count = 0;
            for (int i = 1; i <= n; i++) {
                count += countSetBitsUtil(i);
            }
            return count;
        }
    
        private static int countSetBitsUtil(int num) {
            int count = 0;
            while (num > 0) {
                num &= (num - 1);
                count++;
            }
            return count;
        }
}

// TLE 

// Correct Approach with explanation 
/*
   Space Complexity : O(Log(N))

   where 'N' is the number till which we have to count set bits..
*/
 class Solution{
    public static int countSetBits(int n) {
        // We have 'd' which is the size of repeating window.
        // We are using 'x' to run the loop Log(N) times which is equal to the number of bits in its binary representation.
        int d=2,ans=0,x=n;
        while(x != 0)
        {

            // Using the Mathematical formula explained in the Approach.
            ans+=((n+1)/d)*(d/2) + Math.max((n+1)%d-d/2,0);

            // Window size double every time we shift to the next left bit.
            d*=2;
            x/=2;
        }
        return ans;
    }
}
// Approach:
// Considering the range from 1 to N is equivalent to the range from 0 to N, we can analyze the count of set bits by examining each bit position individually.
// When counting the set bits from 0 to N in the binary representation of numbers, we can observe a repeating pattern at the units place. The pattern consists of a window size of 2, with the sequence "01" repeating. At the next place, the window size doubles to 4, and the pattern becomes "0011". This pattern continues for each subsequent bit position.
// 0000 -> 0
// 0001 -> 1
// 0010 -> 2
// 0011 -> 3
// 0100 -> 4
// 0101 -> 5
// 0110 -> 6
// 0111 -> 7
// 1000 -> 8
// 1001 -> 9
// 1010 -> 10
// To calculate the count of set bits for the complete repetitions of the window, we multiply the number of complete repetitions, which is (N+1)/d, by the count of set bits in each repetition, which is d/2. This gives us ((N+1)/d)*(d/2) set bits from the complete repetitions.

// For the remaining part, which is (N+1)%d, we know that the first d/2 bits are always zeros. To obtain the count of set bits in the remaining part, we subtract d/2 from (N+1)%d. However, if (N+1)%d is less than d/2, it results in a negative number. To avoid this, we take the maximum of ((N+1)%d - d/2) and 0, ensuring a non-negative count.

// By applying this calculation process from the least significant bit to the most significant bit, starting with a window size of 2 and doubling it at each step, we can efficiently count the set bits in the binary representation of numbers from 0 to N.

 

// Algorithm:
// 1. Start with the input number N and initialize variables:

// d = 2: Represents the size of the repeating window.
// ans = 0: Keeps track of the total count of set bits.
// x = N: Helps run the while loop exactly the number of times equal to the number of  bits in n
// Enter a loop that continues until the value of x becomes zero:

// ans += ((N+1)/d)*(d/2) + max((N+1)%d-d/2,0)
// Update the window size d by doubling it and divide x by 2 to move to the next bit position.
// Return the final count of set bits stored in ans.

// Time Complexity
// O(log(N)), where ‘N’ is the given input.

 

// We are performing an addition for every bit in the binary representation of N which is log(N). Hence Time Complexity O(log(N)).

// Space Complexity
// O(1)

 

// We are not using any extra space, thus the constant space complexity.
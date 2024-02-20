
// Question : https://www.codingninjas.com/studio/problems/set-the-rightmost-unset-bit_8160456

public class set_rightmost_unsetbit {
    public static int setBits(int N) {
        if ((N & N + 1) == 0) {
            return N;
        } else {
            int x = N | N + 1;
            return x;
        }
    }
}
// Approach :
// The approach of the code is to use bitwise manipulation to find the position of the least significant unset bit in a non-negative integer ‘N’. Once we have found if there’s any unset bit in ‘N’, we can set the least significant unset bit of ‘N’ to 1 by using the bitwise OR operator with ‘N’ and (N + 1). (N+1) has the same set bits as ‘N’ up to the least significant unset bit of ‘N’.

// For example N=9 is 1001 and N+1=10 is 1010. So N OR (N+1) = 1011 which is 11.

 

// Algorithm:

// Initialize ‘x’ = ’N’
// while ‘x’ AND 1 != 0  #until least significant bit of ‘x’ is not 0
// x = x>>1
// if all bits are set i.e. ‘x’==0
// return ‘N’
// Set the least significant unset bit of ‘N’ to 1 by N = N OR (N+1)
// return ‘N’
// Time Complexity
// O(log N), where ‘N’ is the given input.

 

// This is because in the worst case, the algorithm needs to perform a right shift operation on ‘N’ for every bit in ‘N’ until it finds the position of the least significant unset bit. Since an integer can have at most log(N) bits, hence the time complexity of the algorithm is O(log N).

// Space Complexity
// O(1)

 

// No extra space is used. Hence, the space complexity is O(1).
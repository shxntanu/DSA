
// Question : https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/

public class find_the_prefix_common_of_two_array {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        long n = A.length;
        long bitset = 0;
        // bitset |= (1 << A[0]);
        // bitset |= (1 << B[0]);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if ((bitset & (1L << A[i])) != 0) {
                count++;
            }
            bitset |= (1L << A[i]);

            if ((bitset & (1L << B[i])) != 0) {
                count++;
            }
            bitset |= (1L << B[i]);

            A[i] = count;
        }
        return A;
    }

}
// Explanation : The given code is designed to compute the prefix common array between two arrays `A` and `B`. It utilizes a bitset to keep track of unique elements encountered in both arrays. Let's break down the code:

// 1. `long bitset = 0;`: Initializes a variable `bitset` to 0. This variable is used to keep track of unique elements encountered so far.

// 2. The `for` loop iterates through the arrays `A` and `B` simultaneously:

//    a. `(bitset & (1L << A[i])) != 0`: Checks whether the bit corresponding to the current element in array `A` is set in the `bitset`. If set, it increments the `count`.

//    b. `bitset |= (1L << A[i])`: Sets the bit corresponding to the current element in array `A` in the `bitset`.

//    c. The same logic is applied to array `B`.

//    d. `A[i] = count;`: Assigns the value of `count` to the current index in the result array `A`. This represents the count of unique elements encountered so far in both arrays up to the current index.

// 3. Finally, the modified array `A` is returned.

// In summary, the code computes the prefix common array `A` where each element at index `i` represents the count of unique elements encountered in both arrays `A` and `B` up to index `i`. The use of the bitset helps efficiently track unique elements.
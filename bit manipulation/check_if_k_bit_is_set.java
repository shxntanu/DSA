
// Question : https://www.codingninjas.com/studio/problems/check-whether-k-th-bit-is-set-or-not_5026446

public class check_if_k_bit_is_set {
    static boolean isKthBitSet(int n, int k) {
        int ans = (n >> (k - 1)) & 1;
        return ans == 1;
    }
}

// Explanation:

// n >> (k - 1): Right-shift n by (k - 1) positions. This brings the k-th bit to the least significant position.
// (n >> (k - 1)) & 1: Perform bitwise AND with 1 to extract the least significant bit after the shift. This results in either 0 or 1.
// ans == 1: Check if the extracted bit is equal to 1. If true, it means the k-th bit is set.
// The method returns true if the k-th bit is set in n, and false otherwise.
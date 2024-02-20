public class minimum_steps_to_flip_number {
    public int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        int count = 0;
        while (x > 0) {
            if ((x & 1) == 1) {
                count++;
            }
            x >>= 1;
        }
        return count;
    }
}

// E.g.
// 10 = 1010
// 7 = 0111
// so different bits are, from rightmost bit, 1st, 3rd and 4th.
// We know XOR operation between two numbers will give us these different bits.

//   1010
// ^ 0111
// ____________   
//   1101
// As we see here, in the output number only bits are set which are different in both numbers. (1 ^ 1) = 0 and (1 ^ 0) = 1

// Now, we just have to count these set bits and for that we will use Kernighan’s algorithm to find the number of set bits in a number. The idea behind the algorithm is that when we subtract one from an integer, all the bits following the rightmost set of bits are inverted, turning 1 to 0 and 0 to 1. The rightmost set bit also gets inverted with the bits right to it.
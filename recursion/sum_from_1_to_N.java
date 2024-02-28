package recursion;

// Questions : https://www.geeksforgeeks.org/batch/dsa-4/track/DSASP-Recursion/problem/sum-of-digits-of-a-number

public class sum_from_1_to_N {
    public static int sumOfDigits(int n) {
        if (n == 0) {
            return 0;
        }
        return sumOfDigits(n / 10) + n % 10;
    }
}

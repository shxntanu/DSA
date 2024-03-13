impl Solution {
    pub fn pivot_integer(n: i32) -> i32 {
        let mut total = n*(n+1)/2;
        let mut left_sum = 0;
        for i in 1 .. n + 1 {
            left_sum += i;
            if left_sum == total {
                return i;
            }
            total -= i;
        }
        -1
    }
}
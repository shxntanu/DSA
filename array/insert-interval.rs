use std::cmp::min;
use std::cmp::max;

impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut ans = vec![];
        let n = intervals.len();
        let mut new_interval = new_interval;
        for i in 0 .. n {
            if intervals[i][1] < new_interval[0] {
                ans.push(intervals[i].clone());
            } else if intervals[i][0] > new_interval[1] {
                ans.push(new_interval.clone());
                new_interval = intervals[i].clone();
            } else if intervals[i][1] >= new_interval[0] || intervals[i][0] <= new_interval[1] {
                new_interval[0] = min(new_interval[0], intervals[i][0]);
                new_interval[1] = max(new_interval[1], intervals[i][1]);
            }
        }
        ans.push(new_interval.clone());
        ans
    }
}

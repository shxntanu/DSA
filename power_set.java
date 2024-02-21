import java.util.ArrayList;
import java.util.List;

//Question : https://leetcode.com/problems/subsets/description/

public class power_set {
    public List<List<Integer>> subsets(int[] nums) {
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        ans.add(new ArrayList<>());

        for (int i = 1; i < (1 << n); i++) {
            int x = i;
            List<Integer> subset = new ArrayList<>();
            int count = 0;

            while (x > 0) {
                if ((x & 1) == 1) {
                    subset.add(nums[count]);
                }
                count++;
                x >>= 1;
            }
            ans.add(subset);
        }
        return ans;
    }
}

// Initialization:

// int n = nums.length;: Get the length of the input array nums.
// List<List<Integer>> ans = new ArrayList<>();: Initialize a list to store
// subsets.

// Base Case:

// ans.add(new ArrayList<>());: Add an empty list to represent the subset with
// no elements.

// Generating Subsets:

// The loop for (int i = 1; i < (1 << n); i++) runs through all numbers from 1
// to 2^n - 1 (inclusive), where n is the length of the array.
// int x = i;: Store the current number in variable x.
// List<Integer> subset = new ArrayList<>();: Initialize a list to store the
// current subset.
// Another loop while (x > 0) is used to extract elements from the array based
// on the binary representation of x.
// If the least significant bit of x is 1 ((x & 1) == 1), add the corresponding
// element from nums to the subset.
// Right shift x to move to the next bit.

// Add Subset to Result:

// After constructing a subset, add it to the final result list ans.

// Return Result:

// return ans;: Return the list of all subsets

// Question : https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

public class find_original_array_of_prefix_xor {
    public int[] findArray(int[] pref) {
        int[] ans = new int[pref.length];
        int kuch = 0;
        for (int i = 0; i < pref.length; i++) {
            ans[i] = kuch ^ pref[i];
            kuch = kuch ^ ans[i];
        }
        return ans;
    }
}

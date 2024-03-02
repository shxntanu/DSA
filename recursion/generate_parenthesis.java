package recursion;

import java.util.*;

// Question : https://leetcode.com/problems/generate-parentheses/description/

public class generate_parenthesis {
    List<String> result;

    public List<String> generateParenthesis(int n) {
        result = new ArrayList<>();
        helper(new StringBuilder(), 0, 0, n);
        return result;
    }

    private void helper(StringBuilder sb, int left, int right, int n) {
        if (left == n && right == n)
            result.add(sb.toString());
        if (left < n) {
            sb.append('(');
            helper(sb, left + 1, right, n);
            sb.deleteCharAt(sb.length() - 1);
        }
        if (left > right && right < n) {
            sb.append(')');
            helper(sb, left, right + 1, n);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}

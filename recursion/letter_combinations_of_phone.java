package recursion;

// Question : https://leetcode.com/problems/letter-combinations-of-a-phone-number/

import java.util.*;

public class letter_combinations_of_phone {
    private Map<Character, String> letters = Map.of(
            '2', "abc",
            '3', "def",
            '4', "ghi",
            '5', "jkl",
            '6', "mno",
            '7', "pqrs",
            '8', "tuv",
            '9', "wxyz");
    private String phoneDigits;

    public void recursiveCall(int index, List<String> result, StringBuilder sb) {
        if (sb.length() == phoneDigits.length()) {
            result.add(sb.toString());
            return;
        }
        Character c = phoneDigits.charAt(index);
        String value = letters.get(c);
        for (Character s : value.toCharArray()) {
            sb.append(s);
            recursiveCall(index + 1, result, sb);
            sb.deleteCharAt(sb.length() - 1);
        }
    }

    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        if (digits.length() == 0)
            return result;
        int index = 0;
        this.phoneDigits = digits;
        recursiveCall(index, result, new StringBuilder());
        return result;
    }
}

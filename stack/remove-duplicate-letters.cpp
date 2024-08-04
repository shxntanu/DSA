/**
 * The approach to this involves reading a string character by character,
 * pushing each character to a stack, and popping all characters lexicographically greater than
 * the current character till a lexicographically smaller character is found.
 *
 * An array of counts is used to maintain the relative order between characters.
 */

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> count;
        stack<char> st;
        vector<bool> visited(26, false);

        // Create a hashmap of all the characters
        for(auto i: s) count[i]++;

        for(int i=0; i<s.length(); i++) {
            count[s[i]]--;

            // If the character is already chosen, skip it
            if(visited[s[i] - 'a']) continue;

            // If the top of stack is greater than the current character and has a 
            // count greater than zero, pop all characters till a lexicographically 
            // smaller character is found
            while(!st.empty() && st.top() > s[i] && count[st.top()] > 0) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            // Push it to the stack
            st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }
        
        // Now the stack contains the final string. Pop it in reverse order.
        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};

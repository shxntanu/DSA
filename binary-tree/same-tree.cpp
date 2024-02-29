/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> v1 = preorder(p);
        vector<int> v2 = preorder(q);
        if(v1 == v2) return true;
        return false;
    }

    vector<int> preorder(TreeNode *root) {
        vector<int> vec;
        if(root == NULL) {
            vec.push_back(0);
            return vec;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode *curr = st.top();
            st.pop();
            vec.push_back(curr->val);
            if(curr->right) st.push(curr->right);
            else vec.push_back(-1);
            if(curr->left) st.push(curr->left);
            else vec.push_back(-2);
        }
        return vec;
    }
};

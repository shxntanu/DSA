#include<vector>
using namespace std;

vector<int> preorder(TreeNode *root) {
    vector<int> vec;
    if(root == NULL) {
        vec.push_back(-1);
        return vec;
    }
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        TreeNode *curr = st.top();
        st.pop();
        vec.push_back(curr->val);
        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
    }
    return vec;
}

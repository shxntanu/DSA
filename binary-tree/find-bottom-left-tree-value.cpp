class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int leftMostValue;
        while(!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            leftMostValue = curr->val;
            if(curr->right) q.push(curr->right);
            if(curr->left) q.push(curr->left);
        }
        return leftMostValue;
    }
};

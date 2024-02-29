class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode*>q;
        bool flag=true;
        q.push(root);
        while(!q.empty()){
            int x = q.size() ;
            int prev = flag ? INT_MIN : INT_MAX;
            for(int i=0; i< x; i++){
                TreeNode* curr = q.front();
                q.pop();  
                // If even-indexed row
                if(flag && (curr->val %2==0 || curr->val <=  prev)) return false;
                // Else if odd indexed row
                else if(!flag && (curr->val %2!=0  || curr->val  >= prev)) return false;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                prev= curr->val;
            }
            flag=!flag;
        }
        return true;
    }
};

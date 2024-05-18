int traverse(struct TreeNode *node, int *moves) {
    if(node == NULL) return 0;
    int left = traverse(node->left, moves), right = traverse(node->right, moves);
    *moves += abs(left) + abs(right);
    return node->val + left + right - 1;
}

int distributeCoins(struct TreeNode* root) {
    int moves = 0;
    traverse(root, &moves);
    return moves;
}

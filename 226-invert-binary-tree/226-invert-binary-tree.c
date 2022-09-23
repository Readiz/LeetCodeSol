/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode tn[101];
int tnp;

void copyTree(struct TreeNode* source, struct TreeNode* target) {
    if (source->left) {
        target->right = &tn[tnp];
        copyTree(source->left, &tn[tnp++]);
    } else {
        target->right = 0;
    }
    if (source->right) {
        target->left = &tn[tnp];
        copyTree(source->right, &tn[tnp++]);
    } else {
        target->left = 0;
    }
    target->val = source->val;
}


struct TreeNode* invertTree(struct TreeNode* root){
    tnp = 0;
    if (root) {
        copyTree(root, &tn[tnp++]);
        return &tn[0];
    } else {
        return 0;
    }
    
}
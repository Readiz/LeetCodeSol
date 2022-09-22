/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool valid;
int check(struct TreeNode* v, int h) {
    if (v->left && v->right) {
        int h1 = check(v->left, h + 1);
        int h2 = check(v->right, h + 1);
        int hDiff = h1 - h2;
        if (hDiff > 1 || hDiff < -1) valid = false;
        return (h1 > h2)? h1 : h2;
    } else if (v->left) {
        int h1 = check(v->left, h + 1);
        int hDiff = h1 - h;
        if (hDiff > 1 || hDiff < -1) valid = false;
        return h1;
    } else if (v->right) {
        int h1 = check(v->right, h + 1);
        int hDiff = h1 - h;
        if (hDiff > 1 || hDiff < -1) valid = false;
        return h1;
    }
    return h;
}

bool isBalanced(struct TreeNode* root){
    valid = true;
    if (root) {
        check(root, 0);
    }
    return valid;
}
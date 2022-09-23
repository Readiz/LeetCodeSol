/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int sl[10010];
int slp;
int sr[10010];
int srp;

void dfsl(struct TreeNode* v) {
    if (v->left) {
        dfsl(v->left);
    } else {
        sl[slp++] = -9999;
    }
    if (v->right) {
        dfsl(v->right);
    } else {
        sl[slp++] = -9999;
    }
    sl[slp++] = v->val;
}

void dfsr(struct TreeNode* v) {
    if (v->right) {
        dfsr(v->right);
    } else {
        sr[srp++] = -9999;
    }
    if (v->left) {
        dfsr(v->left);
    } else {
        sr[srp++] = -9999;
    }
    sr[srp++] = v->val;
}

bool isSymmetric(struct TreeNode* root){
    slp = 0;
    srp = 0;
    
    if (root) {
        dfsl(root);
        dfsr(root);
    }
    
    if (slp != srp) return false;
    for(int i = 0; i < slp; ++i) {
        if (sl[i] == sr[i]) continue;
        return false;
    }
    return true;
}
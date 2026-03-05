#include <stddef.h>  // NULL

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bstSearch(struct TreeNode* root, int target) {
    struct TreeNode* curr = root;

    while (curr != NULL) {
        if (target == curr->val) {
            return curr;
        } else if (target < curr->val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return NULL;
}
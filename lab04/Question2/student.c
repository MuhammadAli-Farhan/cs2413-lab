#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



bool isSymmetric(struct TreeNode* root) {

    if (root == NULL)
        return true;

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root->left;
    queue[rear++] = root->right;

    while (front < rear) {

        struct TreeNode* left = queue[front++];
        struct TreeNode* right = queue[front++];

        if (left == NULL && right == NULL)
            continue;

        if (left == NULL || right == NULL)
            return false;

        if (left->val != right->val)
            return false;

        queue[rear++] = left->left;
        queue[rear++] = right->right;

        queue[rear++] = left->right;
        queue[rear++] = right->left;
    }

    return true;
}
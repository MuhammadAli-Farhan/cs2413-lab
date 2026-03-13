#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int sumNumbers(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    struct TreeNode* nodeStack[1000];
    int numStack[1000];
    int top = 0;
    int sum = 0;

    nodeStack[top] = root;
    numStack[top] = root->val;
    top++;

    while (top > 0) {
        top--;

        struct TreeNode* current = nodeStack[top];
        int currentNum = numStack[top];

        if (current->left == NULL && current->right == NULL) {
            sum += currentNum;
        }

        if (current->right != NULL) {
            nodeStack[top] = current->right;
            numStack[top] = currentNum * 10 + current->right->val;
            top++;
        }

        if (current->left != NULL) {
            nodeStack[top] = current->left;
            numStack[top] = currentNum * 10 + current->left->val;
            top++;
        }
    }

    return sum;
}
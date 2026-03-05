#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int max_int(int a, int b) { return (a > b) ? a : b; }

static int abs_int(int x) { return (x < 0) ? -x : x; }

// Returns height if valid, otherwise returns -1
static int check_avl(struct TreeNode* node, long long lo, long long hi) {
    if (node == NULL) return 0;

    long long v = (long long)node->val;

    
    if (!(lo < v && v < hi)) return -1;

    int hl = check_avl(node->left, lo, v);
    if (hl == -1) return -1;

    int hr = check_avl(node->right, v, hi);
    if (hr == -1) return -1;

    if (abs_int(hl - hr) > 1) return -1;

    return 1 + max_int(hl, hr);
}

bool isAVL(struct TreeNode* root) {
    return check_avl(root, LLONG_MIN, LLONG_MAX) != -1;
}
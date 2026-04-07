#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define TABLE_SIZE 1009

static int hash(int key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

static void insert(Node* table[], int key, int value) {
    int i = hash(key);
    Node* n = malloc(sizeof(Node));
    n->key = key;
    n->value = value;
    n->next = table[i];
    table[i] = n;
}

static int find(Node* table[], int key, int* value) {
    Node* c = table[hash(key)];
    while (c) {
        if (c->key == key) {
            *value = c->value;
            return 1;
        }
        c = c->next;
    }
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    Node* table[TABLE_SIZE] = {0};

    for (int i = 0; i < numsSize; i++) {

        int need = target - nums[i];
        int idx;

        if (find(table, need, &idx)) {
            int* ans = malloc(2*sizeof(int));
            ans[0] = idx;
            ans[1] = i;
            *returnSize = 2;
            return ans;
        }

        insert(table, nums[i], i);
    }

    *returnSize = 0;
    return NULL;
}
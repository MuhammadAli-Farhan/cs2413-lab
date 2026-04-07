#include <stdlib.h>

static void swap(int* a, int* b);
static void heapifyUp(int* heap, int index);
static void heapifyDown(int* heap, int size, int index);

int findKthLargest(int* nums, int numsSize, int k) {
    int* heap = malloc(k * sizeof(int));
    int size = 0;

    for (int i = 0; i < numsSize; i++) {
        if (size < k) {
            heap[size] = nums[i];
            heapifyUp(heap, size);
            size++;
        } else if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            heapifyDown(heap, k, 0);
        }
    }

    int ans = heap[0];
    free(heap);
    return ans;
}

static void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

static void heapifyUp(int* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] <= heap[index]) break;
        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

static void heapifyDown(int* heap, int size, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index) break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}
#include "Student.h"

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int total = m + n;

    if (n > nums2Size) n = nums2Size;
    if (total > nums1Size) total = nums1Size;

    int i = m - 1;
    int j = n - 1;
    int k = total - 1;

    while (j >= 0 && k >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
}
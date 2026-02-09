#include "Student.h"

void merge(int* nums1, int nums1Size, int m,
           int* nums2, int nums2Size, int n)
{
    // Use sizes meaningfully (no unused-parameter warnings)
    int k = nums1Size - 1;     // last index in nums1 (should be m + n - 1)
    int i = m - 1;             // last real element in nums1
    int j = nums2Size - 1;     // last element in nums2 (should be n - 1)

    // Merge from the back
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // Copy remaining nums2 elements (if any)
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }

    // Optional: use n too (keeps it "used" if your compiler flags complain later)
    (void)n;
}

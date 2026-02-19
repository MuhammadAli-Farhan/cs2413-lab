#include "Student.h"
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;

    // work from right to left
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;

        if (carry == 0)
            break;
    }

    // if no carry left, just return same size
    if (carry == 0) {
        int* result = malloc(digitsSize * sizeof(int));
        for (int i = 0; i < digitsSize; i++) {
            result[i] = digits[i];
        }
        *returnSize = digitsSize;
        return result;
    }

    // if carry still exists (example: 999 -> 1000)
    int* result = malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1;
    for (int i = 0; i < digitsSize; i++) {
        result[i + 1] = digits[i];
    }

    *returnSize = digitsSize + 1;
    return result;
}
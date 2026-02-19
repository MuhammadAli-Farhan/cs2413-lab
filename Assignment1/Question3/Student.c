#include "Student.h"
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;

    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;

        if (carry == 0) break;
    }

    if (carry == 0) {
        int* out = malloc(digitsSize * sizeof(int));
        for (int i = 0; i < digitsSize; i++) out[i] = digits[i];
        *returnSize = digitsSize;
        return out;
    }

    int* out = malloc((digitsSize + 1) * sizeof(int));
    out[0] = 1;
    for (int i = 0; i < digitsSize; i++) out[i + 1] = digits[i];
    *returnSize = digitsSize + 1;
    return out;
}

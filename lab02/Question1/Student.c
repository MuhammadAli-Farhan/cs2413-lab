#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen

bool isValid(const char *s) {
    if (!s) return false;

    size_t n = strlen(s);
    char st[n];
    int top = 0;

    for (size_t i = 0; i < n; i++) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            st[top++] = c;
        } else {
            if (top == 0) return false;

            char need = (c == ')') ? '(' : (c == ']') ? '[' : '{';
            if (st[--top] != need) return false;
        }
    }
    return top == 0;
}

// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

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

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
    if (s == NULL) return false;

    int len = strlen(s);

    if (len % 2 != 0) return false;   // odd length can't be valid

    char stack[len];   // simple stack
    int top = -1;      // stack empty

    for (int i = 0; i < len; i++) {

        char c = s[i];

        // if opening bracket → push
        if (c == '(' || c == '[' || c == '{') {
            top++;
            stack[top] = c;
        }
        else {  // closing bracket

            if (top == -1) return false;  // nothing to match

            char last = stack[top];

            if ((c == ')' && last == '(') ||
                (c == ']' && last == '[') ||
                (c == '}' && last == '{')) {
                top--;   // pop
            }
            else {
                return false;  // wrong match
            }
        }
    }

    // valid only if stack is empty
    if (top == -1)
        return true;
    else
        return false;
}

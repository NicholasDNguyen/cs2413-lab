// Question1/student.c
// ------------------------------------------------------------
// CS Lab03 - Reverse Linked List 
//
// TODO:
//   Implement reverseList(head) to reverse a singly linked list.
//
// Rules:
// - Do not allocate new nodes.
// - Do not use recursion.
// - Return the new head pointer.
// ------------------------------------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "student.h"

struct ListNode* reverseList(struct ListNode* head) {
    // TODO: implement
    // Hints (optional):
    // - Keep track of previous and current pointers.
    // - Iterate until current becomes NULL.
    // Previous pointer starts as NULL
    struct ListNode *prev = NULL;

    // Current pointer starts at head
    struct ListNode *curr = head;

    // Traverse entire list
    while (curr != NULL) {

        // Store next node
        struct ListNode *next = curr->next;

        // Reverse the link
        curr->next = prev;

        // Move pointers forward
        prev = curr;
        curr = next;
    }

    // prev is the new head
    return prev;

}

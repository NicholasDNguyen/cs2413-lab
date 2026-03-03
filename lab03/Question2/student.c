// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement
      // If list is empty or only one node, nothing to swap
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // The second node will become the new head
    struct ListNode *newHead = head->next;

    // Previous tail of swapped pair
    struct ListNode *prev = NULL;

    // Current pointer to traverse list
    struct ListNode *curr = head;

    while (curr != NULL && curr->next != NULL) {

        // Identify the two nodes to swap
        struct ListNode *first = curr;
        struct ListNode *second = curr->next;

        // Save pointer to next pair
        struct ListNode *nextPair = second->next;

        // Swap the two nodes
        second->next = first;
        first->next = nextPair;

        // Connect previous pair to current swapped pair
        if (prev != NULL) {
            prev->next = second;
        }

        // Move prev to the end of swapped pair
        prev = first;

        // Move curr to next pair
        curr = nextPair;
    }

    return newHead;
}

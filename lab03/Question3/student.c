// Question3/student.c
// ------------------------------------------------------------
// CS Lab03 - Linked List Cycle 
//
// TODO:
//   Implement hasCycle(head) using fast/slow pointers.
//
// Rules:
// - Do not allocate new nodes.
// - Do not modify the list.
// ------------------------------------------------------------

#include "student.h"

bool hasCycle(struct ListNode *head) {
    // TODO: implement
    // If list is empty or has only one node, no cycle
    if (head == NULL || head->next == NULL) {
        return false;
    }

    // Slow pointer moves 1 step
    struct ListNode *slow = head;

    // Fast pointer moves 2 steps
    struct ListNode *fast = head;

    // Traverse the list
    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;           // move 1 step
        fast = fast->next->next;     // move 2 steps

        // If they meet, cycle exists
        if (slow == fast) {
            return true;
        }
    }

    // If we reach NULL, no cycle
    return false;

}

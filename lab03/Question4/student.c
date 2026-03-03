// Question4/student.c
// ------------------------------------------------------------
// CS Lab03 - Middle Node of Linked List
//
// TODO:
//   Implement middleNodeValue(head) using fast/slow pointers.
//
// Notes:
// - If even length, return the second middle.
// - Do not allocate new nodes.
// ------------------------------------------------------------

#include "Student.h"

int middleNodeValue(struct ListNode *head) {
    // TODO: implement
    // If list is empty (defensive check)
    if (head == NULL) {
        return 0;  // or handle according to your lab spec
    }

    // Slow pointer moves 1 step
    struct ListNode *slow = head;

    // Fast pointer moves 2 steps
    struct ListNode *fast = head;

    // Move until fast reaches end
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // move 1 step
        fast = fast->next->next;     // move 2 steps
    }

    // Slow will be at the middle
    return slow->val;

}

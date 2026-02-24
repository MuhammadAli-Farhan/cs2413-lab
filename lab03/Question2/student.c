#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* newHead = head->next;  
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL && curr->next != NULL) {
        struct ListNode* first = curr;
        struct ListNode* second = curr->next;
        struct ListNode* nextPair = second->next;

        
        second->next = first;
        first->next = nextPair;

        if (prev != NULL)
            prev->next = second;

        
        prev = first;
        curr = nextPair;
    }

    return newHead;
}
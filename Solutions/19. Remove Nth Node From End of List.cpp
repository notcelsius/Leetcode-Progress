// Date Completed: 12/5/2024

// Leetcode Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Time Complexity: O(n)
// Space Complexity: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Will be using the 2 pointers method
        ListNode* first = head; // first pointer moves first
        ListNode* second = head;    // second pointer moves second

        // the first pointer should always be n nodes ahead of the second
        // or in other words the second pointer is n nodes behind the first pointer
        // so move the first pointer first n nodes forward
        for (int i = 0; i < n; i++) {
            first = first->next;
        }

        // if the first pointer is NULL, then we know that all n nodes were traversed
        // which means that the node that is going to be removed is the head
        if (first == NULL) {
            return head->next;
        }

        // moves both the first and the second pointer until the first reaches the end of the list
        // this does not actually reach NULL though, so the second pointer will be on the node before the one that should be removed
        while (first->next) {
            first = first->next;
            second = second->next;
        }

        // remove the node that should be removed
        second->next = second->next->next;

        // returns the head of the list
        return head;

        // example: 1 -> 2 -> NULL and n = 2
        // the first pointer will reach NULL and the head will be removed
        // notice how in this case the first pointer was n=2 nodes ahead of the one that needed to be removed

        // example 1 -> 2 -> 3 -> 4 -> NULL and n = 2
        // the first pointer will end its first move cycle at 3 and then its second cycle at 4
        // notice how when it reaches 4, the second pointer is at 2 which is n=2 nodes behind the first pointer
        // this is correct because we need to remove the node after the second pointer


    }
};
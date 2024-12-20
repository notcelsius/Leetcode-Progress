// Date Completed: 12/20/2024

// Leetcode Problem: https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {   // if there is no list or only one node in list
            return head;    // then no need for reversing
        }
        // basically imagine NULL -> 1 -> 2 -> NULL
        // the first NULL is prev
        // 1 is curr
        // 2 will be temp
        // by the end of 1st iteration curr will be at 2 and prev will be at 1
        // then 2nd iteration curr will be at NULL and prev will be at 2
        // this is where we end it via checking if curr is valid and return prev which is start of reversed list
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp;
        while (curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
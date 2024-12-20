// Date Completed: 12/19/2024

// Leetcode Problem: https://leetcode.com/problems/min-stack/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) { // if the list is empty
            return head;    // then return an empty list
        }
        ListNode* curr = head;  // keeping track of where in the list I am
        while (curr->next) {    // no need to have curr be the last value in the list
            if (curr->next->val == curr->val) { // if there is a duplicate like 1->1->2
                curr->next = curr->next->next;  // set it to be 1->2 while keeping curr on 1
                                                // do this because 1->1->1 may happen which results in 1->1 with curr still in 1st 1
            }
            else {  // no duplicate
                curr = curr->next;  // move forward to check next one
            }
        }
        return head;    // return start of the list
    }
};
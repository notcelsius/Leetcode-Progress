// Date Completed: 12/20/2024

// Leetcode Problem: https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // if one of the lists is empty, then the other list is the whole merged list
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        ListNode* head; // keeps track of start of list
        ListNode* curr; // curr ptr to traverse through list
        // figuring out if head should be list1 or list2
        if (list1->val > list2->val) {
            head = list2;
            curr = list2;
            list2 = list2->next;
        }
        else {
            head = list1;
            curr = list1;
            list1 = list1->next;
        }
        while (list1 && list2) {    // while both list1 and list2 are valid
            // link them up accordingly
            if (list1->val > list2->val) {
                curr->next = list2;
                list2 = list2->next;
            }
            else {
                curr->next = list1;
                list1 = list1->next;
            }
            curr = curr->next;  // increment curr so it stays updated
        }
        // if one of the lists still has stuff in it, then just append it to the linked list
        if (list1) {
            curr->next = list1;
        }
        if (list2) {
            curr->next = list2;
        }
        return head;    // return head of list found at start
    }
};
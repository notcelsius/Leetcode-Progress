// Date Completed: 12/20/2024

// Leetcode Problem: https://leetcode.com/problems/linked-list-cycle/description/

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

// use a slow and fast ptr approach
// basically slow ptr moves forward by 1 and fast ptr moves by forward 2
// if fast ptr is able to reach end of list (NULL) then it means there was no cycle
// if there is a cycle, then the fast ptr will eventually catch up to the slow ptr and that will indicate there is a cycle
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;  // start fast ptr at head
        ListNode* slow = head;  // start slow ptr at head

        while (fast && fast->next) {    // make sure fast and fast->next is valid because we will be checking their nexts
            fast = fast->next->next;    // move fast forward by 2
            slow = slow->next;          // move slow forward by 1
            
            if (fast == slow) {         // detect if there is a cycle
                return true;            // return true if there is a cycle
            }
        }
        
        return false;                   // return false if there is no cycle
    }
};
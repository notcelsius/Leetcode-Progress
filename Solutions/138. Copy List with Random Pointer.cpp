// Date Completed: 12/29/2024

// Leetcode Problem: https://leetcode.com/problems/copy-list-with-random-pointer/

// Time Complexity: O(n)
// Space Complexity: O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) { // if list is empty new list will be empty
            return head;
        }
        unordered_map<Node*,Node*> origToNew;   // stores original nodes to their deep copies
        Node* curr = head;
        // create new copies of all the nodes
        while (curr) {
            origToNew[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        // set the random and next ptrs for the deep copies
        while (curr) {
            origToNew[curr]->next = origToNew[curr->next];
            origToNew[curr]->random = origToNew[curr->random];
            curr = curr->next;       
        }
        // return head of new list
        return origToNew[head];
        
    }
};
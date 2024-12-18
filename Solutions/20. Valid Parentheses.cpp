// Date Completed: 12/17/2024

// Leetcode Problem: https://leetcode.com/problems/valid-parentheses/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> paren; // right to left parentheses key value pair
        stack<char> stk; // keeps track of left parentheses
        paren[')'] = '(';
        paren['}'] = '{';
        paren[']'] = '[';
        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') { // if is left parentheses
                stk.push(c);    // add it to stack
            }
            else {  // if right parentheses
                if (stk.empty() || stk.top() != paren[c]) { // if there is no corresponding left parentheses or its not the correct one
                    return false;   // is false
                }
                stk.pop();  // cancel out valid parentheses pair
            }
            
        }
        if (stk.empty()) {  // by the end of the string all parentheses should've been processed and cancelled
            return true;    // so return true
        }
        else {  // still stuff left in stack
            return false;   // still parentheses left after string processed so return false
        }
    }
};
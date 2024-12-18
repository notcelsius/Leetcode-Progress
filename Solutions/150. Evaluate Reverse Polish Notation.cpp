// Date Completed: 12/17/2024

// Leetcode Problem: https://leetcode.com/problems/evaluate-reverse-polish-notation/

// Time Complexity: O(n)
// Space Complexity: O(n)

// not much too explain here
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> eqn;
        int first;
        int second;
        // second operand first
        for (string s: tokens) {
            if (s == "/") {
                first = eqn.top();
                eqn.pop();
                second = eqn.top();
                eqn.pop();
                eqn.push(second/first);
            }
            else if (s == "+") {
                first = eqn.top();
                eqn.pop();
                second = eqn.top();
                eqn.pop();
                eqn.push(second+first);
            }
            else if (s == "-") {
                first = eqn.top();
                eqn.pop();
                second = eqn.top();
                eqn.pop();
                eqn.push(second-first);
            }
            else if (s == "*") {
                first = eqn.top();
                eqn.pop();
                second = eqn.top();
                eqn.pop();
                eqn.push(second*first);
            }
            else {
                eqn.push(stoi(s));
            }
        }
        return eqn.top();
    }
};
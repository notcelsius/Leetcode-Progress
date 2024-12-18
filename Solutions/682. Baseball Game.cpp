// Date Completed: 12/17/2024

// Leetcode Problem: https://leetcode.com/problems/baseball-game/

// Time Complexity: O(n)
// Space Complexity: O(n)

// not much to explain on this one
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record;
        int score = 0;
        for (string i: operations) {
            if (i == "+") {
                int first = record.top();
                record.pop();
                int second = record.top();
                score += first + record.top();
                record.push(first);
                record.push(first+second);
            }
            else if (i == "D") {
                score += (record.top() * 2);
                record.push(2 * record.top());
            }
            else if (i == "C") {
                score -= record.top();
                record.pop();
            }
            else {
                record.push(stoi(i));
                score += stoi(i);

            }
        }
        return score;
    }
};
// Date Completed: 12/19/2024

// Leetcode Problem: https://leetcode.com/problems/daily-temperatures/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();    // size of temperature
        vector<int> res(n,0);   // creates a result vector with everything being 0 because the last day will be 0 no matter what
        stack<pair<int,int>> stk;   // pair <temp , index>
        for (int i = 0; i < temperatures.size(); i++) { // go through all temperatures
            int temp = temperatures[i]; // get current temperature of index
            while (!stk.empty() && temp > stk.top().first) {    // once find a day with a higher temp then empty out the stack
                                                                // 77 74 71 80 means 77 74 71 will be in the stack
                res[stk.top().second] = i - stk.top().second;   // res[index of temp] = index of curr temp - index of temp
                                                                // is like distance away from temp
                stk.pop();                                      // get rid of the temp in stack once done with it
            }
            stk.push(make_pair(temp,i));    // add the curr temp to the stack
        }
        return res; // return result vector
    }
};
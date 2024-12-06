// Date Completed: 12/6/2024

// Leetcode Problem: https://leetcode.com/problems/merge-intervals/

// Time Complexity: O(nlogn)
// Space Complexity: O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());   // sorts the intervals by start time
        vector<vector<int>> result; // will store the merged intervals
        int index = 0;  // index keeps track of which interval on in intervals
        while (index < intervals.size()) {  // while valid internval in intervals
            int start = intervals[index][0];    // gets start time
            int finish = intervals[index][1];   // gets finish time
            while (index < intervals.size() - 1 && intervals[index+1][0] <= finish) {   // keeps going until the next interval after index has a larger start time than index's finish time
                index++;    // increases index
                if (finish < intervals[index][1]) { // edge case of when next interval has a smaller finish time
                    finish = intervals[index][1];   // ex: [0,5] [0,3]
                }
            }
            result.push_back({start, finish});  // push the merged interval into the vector
            index++;    // goes to the next interval in intervals

        }
        return result;  // returns all the merged intervals
    }

};
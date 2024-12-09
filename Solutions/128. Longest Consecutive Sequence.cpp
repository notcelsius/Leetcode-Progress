// Date Completed: 12/9/2024

// Leetcode Problem: https://leetcode.com/problems/longest-consecutive-sequence/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers; // use a set for O(1) lookup
        // fill the set up from the vector
        for (int num: nums) {
            numbers.insert(num);
        }
        int longest = 0;    // keeps track of length of longest sequence
        for (int num: numbers) {
            if (!numbers.contains(num-1)) { // if the start of a new sequence
                int length = 1; // there is currently 1 number in the sequence
                while (numbers.contains(num+length)) {  // while the next number in the sequence is still existing
                    length++;   // increment length to find the next number in the sequence
                }
                longest = max(longest,length);  // compare the length of the current sequence with the length of the current longest sequence and find new longest one
            }
        }
        return longest;

    }
};
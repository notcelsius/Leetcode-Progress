// Date Completed: 1/2/2025

// Leetcode Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// Time Complexity: O(n)
// Space Complexity: O(m) where m is the length of the longest substring without repeating characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // using sliding window technique
        int l = 0;
        int r = 0;
        unordered_set<char> chars;
        int longest = 0;
        while (r < s.length()) {
            while (chars.find(s[r]) != chars.end()) {  // char is in set/window
                chars.erase(s[l]);  // remove s[l] from set
                l++;    // increment l
            }

            longest = max(longest, r - l + 1);  // update the longest
            chars.insert(s[r]); // add s[r] to the set
            r++;    // increment r
        }
        return longest; // return longest
    }
};
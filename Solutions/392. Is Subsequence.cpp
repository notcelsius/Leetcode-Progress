// Date Completed: 12/4/2024

// Leetcode Problem: https://leetcode.com/problems/is-subsequence/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tIndex = 0; // keeps track of index in s
        int sIndex = 0; // keeps track of index in t
        while (tIndex < t.length() && sIndex < s.length()) {    // while both indexes are inbounds
            if (s[sIndex] == t[tIndex]) {   // if the letters are the same
                sIndex++;   // go to the next letter in s
                tIndex++;   // same with t
            }
            else {  // letters are not the same
                tIndex++;   // only go to next letter in t
            }
        }
        if (sIndex == s.length()) { // sIndex will have traversed all of s if it was a valid subsequence
            return true;
        }
        else {  // if sIndex did not fully traverse s then it is not valid subsequence
            return false;
        }
    }
};
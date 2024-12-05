// Date Completed: 12/4/2024

// Leetcode Problem: https://leetcode.com/problems/longest-common-prefix/

// Time Complexity: O(k * n) where k is the length of the shortest string and n is the number of strings in strs
// Space Complexity: O(k)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = "";    // starts off the longest common prefix as empty
        for (int i = 0; i < strs[0].length(); i++) {    // iterates through the first string in strs
            for (int j = 1; j < strs.size(); j++) { // for all other strings in strs
                if (i >= strs[j].size() || strs[0][i] != strs[j][i]) {  // first check that the current index is valid, then check if they match
                    return lcp; // if they don't match, then we found the longest common prefix
                }
            }
            lcp += strs[0][i];  // went through all strings in strs and all had the common character so add it to the lcp
        }
        return lcp; // return the lcp after going through all characters in all strings
    }
};
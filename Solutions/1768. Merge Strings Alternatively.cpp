// Date Completed: 12/3/2024

// Leetcode Problem: https://leetcode.com/problems/merge-strings-alternately/description/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;  // index of where we are in the char array
        string merged = "";  // what we are going to return
        while (i < min(word1.length(), word2.length())) {   // while i is still in word for string1 and string2
            merged += word1[i]; // add character to merged
            merged += word2[i]; // add character to merged
            i++;    // increment i
        }
        while (i < word1.length()) {    // if there is still characters left in word1
            merged += word1[i]; // add them to the merged word
            i++;
        }    
        while (i < word2.length()) {    // if there is still characters left in word2
            merged += word2[i]; // add them to the merged word
            i++;
        }    
        return merged;  // return the merged word
    }
};
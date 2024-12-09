// Date Completed: 12/8/2024

// Leetcode Problem: https://leetcode.com/problems/group-anagrams/

// Time Complexity: O(m * n) where m is the number of words in strs and n is the length of the longest word
// Space Complexity: O(m)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;  // will be returned and stores groups of anagrams
        unordered_map<string, vector<string>> keyToListOfAnagrams; // has a key to a list of anagrams pairs
        for (string str: strs) {    // go through each word
            string key; // initialize a key
            int alphabet[26] = {0}; // initialize an alphabet array
            // get frequency of each letter in the alphabet
            for (char c: str) {
                alphabet[c-'a']++;
            }
            // create the key
            for (int i = 0; i < 26; i++) {
                key += ',' + to_string(alphabet[i]);
            }
            // add the pair to its appropiate place in the map
            keyToListOfAnagrams[key].push_back(str);

        }
        for (auto& pair: keyToListOfAnagrams) { // go through the key to list of anagrams pairs
            result.push_back(pair.second);  // add the lists of anagrams to result
        }
        return result;  // return the list of lists of anagrams
    }
};
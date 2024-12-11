// Date Completed: 12/11/2024

// Leetcode Problem: https://leetcode.com/problems/encode-and-decode-strings/

// Time Complexity: O(m) where m is the length of all strings combined
// Space Complexity: O(1)

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = ""; // will store the result of encoding 1 string
        for (string s: strs) {
            int length = s.length();    // keeps track of length of string
            result += to_string(length);    // appends it to result
            result += "#";  // adds the delimiter so that I can separate the length from a number in the string
            result += s;    // adds s to string
        }
        return result;  // returns the encoded list of strings
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;  // stores the decoded list of strings
        int i  = 0; // index for going through s
        while (i < s.length()) {    // makes sure i is within s
            int j = i;  // beginning of number
            while (s[j] != '#') {   // goes till finds the delimiter, which signifies the end of the number
                j++;    // when while loop ends, j will be on the delimiter
            }
            int length = stoi(s.substr(i,j-i)); // the number will be the beginning of number to before the delimiter
            i = j + 1;  // j is currently on the delimiter, so the actual string will be the next character after the delimiter
            result.push_back(s.substr(i, length));  // push back beginning of the string to the end of it
            i += length;    // set i to the beginning of the next number
            
        }
        return result;  // return decoded list of strings
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
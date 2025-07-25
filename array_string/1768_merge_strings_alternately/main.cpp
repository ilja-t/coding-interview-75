/*
You are given two strings word1 and word2. Merge the strings by adding letters
in alternating order, starting with word1. If a string is longer than the
other, append the additional letters onto the end of the merged string.
Return the merged string.
*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0, j = 0;
        while (i < word1.size() || j < word2.size()) {
            if (i < word1.size()) {
                result += word1[i++];
            }
            if (j < word2.size()) {
                result += word2[j++];
            }
        }
        return result; 
    }
};

// Example usage
int main() {
    Solution solution;
    string word1 = "abc";
    string word2 = "pqr";
    string merged = solution.mergeAlternately(word1, word2);
    cout << "Merged string: " << merged << endl; // Output: "apbqcr"
    return 0;
}
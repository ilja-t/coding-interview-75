/*
For two strings s and t, we say "t divides s" if and only if 
s = t + t + t + ... + t + t (i.e., t is concatenated with itself
one or more times).

Given two strings str1 and str2, return the largest string x such that
x divides both str1 and str2.

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If concatenating in both orders gives different results, no common divisor exists
        if (str1 + str2 != str2 + str1)
            return "";

        // Compute the greatest common divisor of the lengths
        int gcdLen = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLen);
    }

private:
    // Helper function to compute GCD of two integers
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    Solution sol;
    struct TestCase {
        std::string str1;
        std::string str2;
        std::string expected;
    };

    std::vector<TestCase> tests = {
        {"ABCABC", "ABC", "ABC"},
        {"ABABAB", "ABAB", "AB"},
        {"LEET", "CODE", ""},
        {"", "", ""},
        {"A", "A", "A"},
        {"AAAA", "AA", "AA"},
        {"ABAB", "ABAB", "ABAB"},
        {"XYZXYZ", "XYZ", "XYZ"},
        {"ABCDEF", "ABC", ""},
        {"ABABABAB", "ABAB", "AB"}
    };

    for (const auto& test : tests) {
        std::string result = sol.gcdOfStrings(test.str1, test.str2);
        std::cout << "gcdOfStrings(\"" << test.str1 << "\", \"" << test.str2 << "\") = \""
                  << result << "\" | Expected: \"" << test.expected << "\""
                  << (result == test.expected ? " [PASS]" : " [FAIL]") << std::endl;
    }
    return 0;
}
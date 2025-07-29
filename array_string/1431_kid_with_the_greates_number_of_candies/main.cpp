/*
There are n kids with candies. You are given an integer array candies, where
each candies[i] represents the number of candies the ith kid has, and an integer
extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after
giving the ith kid all the extraCandies, they will have the greatest number of
candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size(), false);
        int maxCandies = 0;
        for (int candy : candies) {
            if (candy > maxCandies) {
                maxCandies = candy;
            }
        }
        for (int i = 0; i < candies.size(); ++i) {
            if (candies[i] + extraCandies >= maxCandies) {
                result[i] = true;
            }
        }
        return result;
    }
};

// Example usage   
int main() {
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> result = Solution().kidsWithCandies(candies, extraCandies);
    // result should be [true, true, true, false, true]
    cout << "Result: ";
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << (result[i] ? "true" : "false");
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}   


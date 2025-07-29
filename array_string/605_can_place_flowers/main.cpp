/*
You have a long flowerbed in which some of the plots are planted, and some are
not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and
1 means not empty, and an integer n, return true if n new flowers can be planted
in the flowerbed without violating the no-adjacent-flowers rule and false
otherwise.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int gap = 1; // Start with a gap of 1 to account for the first plot
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (n == 0) {
                return true; // If no more flowers need to be planted
            }
            if (flowerbed[i] == 0) {
                gap++; // Increase gap for empty plot
            } else {
                gap = 0; // Reset gap when a flower is found
            }
            if (gap == 3) { // We can plant a flower in the previous two empty plots
                n--;
                gap = 1; // Reset gap after planting
            }
        }
        if (gap == 2) { // If the last plot is empty, we can plant one more flower
            n--;
        }
        return n <= 0;
    }
};

int main() {
    Solution solution;
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    bool result = solution.canPlaceFlowers(flowerbed, n);
    // Expected output: true
    cout << (result ? "true" : "false") << endl;
    return 0;
}
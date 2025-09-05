#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstRepeatedElement(vector<int>& nums, int k) {
    unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++;
    }

    for (int num : nums) {
        if (freq[num] == k) {
            return num;
        }
    }

    return -1;
}

int main() {
    vector<int> input = {6, 6, 6, 6, 7, 7, 8, 8, 8};
    int k = 3;

    cout << firstRepeatedElement(input, k) << endl;

    return 0;
}

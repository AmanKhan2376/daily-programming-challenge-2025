#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    long long missingNumber(vector<int>& nums) {
        long long n = nums.size(), sum = 0;
        long long missing =  accumulate(nums.begin(), nums.end(), 0LL);
        for(long long i = 1; i <= n + 1; i ++) {
            sum += i;
        }
        return sum  - missing;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 5}; 
    cout << Solution().missingNumber(nums);
    return 0;
}

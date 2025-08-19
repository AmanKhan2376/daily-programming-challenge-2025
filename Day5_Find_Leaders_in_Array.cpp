#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> leadersInArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int greatest = INT_MIN;

        for(int i = n - 1; i >= 0; i --) { 
            if(nums[i] > greatest) {
                greatest = nums[i];
                ans.push_back(greatest);
            }
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 0};

    vector<int> ans = Solution().leadersInArray(nums);

    for (int num : ans) cout << num << " ";
    cout << endl;

    return 0;
}

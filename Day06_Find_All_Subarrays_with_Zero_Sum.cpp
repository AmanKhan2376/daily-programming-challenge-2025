#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> subarraysWithZeroSum(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> result;
        unordered_map<int, vector<int>> prefixMap;

        int prefixSum = 0;
        prefixMap[0].push_back(-1);

        for(int i = 0; i < n; i++) {
            prefixSum += nums[i];

            if(prefixMap.find(prefixSum) != prefixMap.end()) {
                for(int startIdx : prefixMap[prefixSum]) {
                    result.push_back({startIdx + 1, i}); 
                }
            }

            prefixMap[prefixSum].push_back(i);
        }

        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, -3, 3, -1, 2};
    vector<pair<int,int>> ans = Solution().subarraysWithZeroSum(nums);

    for(auto p : ans) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; 
    vector<int> result;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {7, 7, 7, 7};
    int k = 1;

    vector<int> output = maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximums: ";
    for (int x : output) cout << x << " ";
    cout << endl;

    return 0;
}

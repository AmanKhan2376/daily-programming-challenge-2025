#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) {
            return {};
        }

        int low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            } else if (arr[mid] == 2) {
                swap(arr[mid], arr[high]);
                high--;
            } else {
                mid++;
            }
        }
    return arr;
    }
};

int main() {
    vector<int> arr = {0, 1, 2, 1, 0, 2}; 
    vector<int> ans = Solution().sortArray(arr);
    for (int i : ans) cout << i << " ";
    return 0;
}

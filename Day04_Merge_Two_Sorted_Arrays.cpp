#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int i, int j) {
        if (arr1[i] > arr2[j]) swap(arr1[i], arr2[j]);
    }

    int nextGap(int gap) {
        if (gap <= 1) return 0;
        return (gap / 2) + (gap % 2);
    }

    void mergeTwoSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        int gap = nextGap(n + m);

        while (gap > 0) {
            int i = 0, j = i + gap;
            while (j < n + m) {
                
                if (i < n && j < n) {
                    if (arr1[i] > arr1[j]) swap(arr1[i], arr1[j]);
                } else if (i < n && j >= n) {
                    swapIfGreater(arr1, arr2, i, j - n);
                } else {
                    if (arr2[i - n] > arr2[j - n]) swap(arr2[i - n], arr2[j - n]);
                }

                i++; j++;
            }

            gap = nextGap(gap);
        }
    }
};

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};

    Solution().mergeTwoSortedArrays(arr1, arr2);

    for (int num : arr1) cout << num << " ";
    cout << endl;
    for (int num : arr2) cout << num << " ";
    cout << endl;

    return 0;
}

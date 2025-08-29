#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> lastIndex(256, -1); 
        int maxLen = 0;
        int left = 0; 

        for (int right = 0; right < n; right++) {
            char c = s[right];
            if (lastIndex[c] >= left) {
                left = lastIndex[c] + 1;
            }
            lastIndex[c] = right; 
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// Example usage
int main() {
    string s = "abcabcbb";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}

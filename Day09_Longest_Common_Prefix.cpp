#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (strs.empty()) return "";
        string ans;
        string prefix = strs[0];
        for (int i = 1; i < n; i++) {
            ans = "";
            int minLength = min(prefix.length(), strs[i].length());
            string s = strs[i];
            for (int j = 0; j < minLength; j++) {
                if (prefix[j] == s[j]) {
                    ans += s[j];
                } else {
                    break;
                }
            }
            prefix = ans;
        }
        return prefix;
    }
};

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << Solution().longestCommonPrefix(strs) << endl;
    return 0;
}

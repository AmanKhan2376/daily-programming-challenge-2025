#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> permute(string s) {
        vector<string> result;
        sort(s.begin(), s.end());
        do {
            result.push_back(s);
        } while (next_permutation(s.begin(), s.end()));
        return result;
    }
};

int main() {
    string s = "aab";
    vector<string> ans = Solution().permute(s);
    for (string str : ans) {
        cout << str << " ";
    }
    return 0;
}

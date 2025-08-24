#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>  // for sort
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (auto& s : strs) {                
            string key = s;                   
            sort(key.begin(), key.end());     
            map[key].push_back(s);            
        }

        vector<vector<string>> result;
        result.reserve(map.size());           
        for (auto& it : map) {
            result.push_back(move(it.second));
        }

        return result;
    }
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = Solution().groupAnagrams(strs);
    cout << "[";
    for (auto &group : ans) {
        cout << "[";
        for (int i = 0; i < group.size(); i++) {
            cout << group[i];
            if (i < group.size() - 1) cout << ",";
        }
        cout << "]";
    }
    cout << "]" << endl;
    return 0;
}

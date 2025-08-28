#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long atMostK(const string &s, int K) {
    vector<int> freq(256, 0);
    int distinct = 0, left = 0;
    long long res = 0;

    for (int right = 0; right < s.size(); right++) {
        if (freq[s[right]]++ == 0) distinct++;

        while (distinct > K) {
            if (--freq[s[left]] == 0) distinct--;
            left++;
        }

        res += (right - left + 1);
    }
    return res;
}

long long countAns(const string &s, int K) {
    if (K == 0) return 0;
    return atMostK(s, K) - atMostK(s, K - 1);
}

int main() {
    string s = "aabacbebebe";
    int k = 3;

    cout << countAns(s, k) << endl; 

    return 0;
}

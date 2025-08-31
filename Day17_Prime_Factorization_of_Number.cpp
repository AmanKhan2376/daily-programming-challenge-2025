#include <iostream>
#include <vector>
using namespace std;

vector<int> primeFactors(int num) {
    vector<int> ans;
    if (num <= 1) return ans;

    while(num % 2 == 0) {
        ans.push_back(2);
        num /= 2;
    }

    while(num % 3 == 0) {
        ans.push_back(3);
        num /= 3;
    }

    for(int i = 5; i * i <= num; i += 6) {
        while(num % i == 0) {
            ans.push_back(i);
            num /= i;
        }
        while(num % (i + 2) == 0) {
            ans.push_back(i + 2);
            num /= (i + 2);
        }
    }

    if(num > 1) ans.push_back(num);

    return ans;
}

int main() {
    int input;
    cout << "Enter a number: ";
    cin >> input;

    vector<int> output = primeFactors(input);
    for (int i = 0; i < output.size(); i++) {
        if (i != 0) cout << " ";
        cout << output[i];
    }
    return 0;
}

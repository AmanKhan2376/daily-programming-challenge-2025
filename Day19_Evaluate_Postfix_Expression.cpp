#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int evalRPN(string tokens) {
    stack<int> s;
    stringstream ss(tokens);
    string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
            else s.push(a / b);
        } else {
            s.push(stoi(token)); 
        }
    }

    return s.top();
}

int main() {
    string tokens =   "2 1 + 3 *"; 
    cout << "Result: " << evalRPN(tokens) << endl; 
    return 0;
}

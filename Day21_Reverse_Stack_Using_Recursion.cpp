#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void insertAtBottom(stack<int> &st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(top);
}

void reverseStack(stack<int> &st) {
    if (st.empty()) return;
    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, top);
}

void printStack(stack<int> st) {
    vector<int> temp;
    while (!st.empty()) {
        temp.push_back(st.top());
        st.pop();
    }
    cout << "[";
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i];
        if (i != temp.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    stack<int> st;
    vector<int> input = {1, 2, 3, 4};
    for (int i = input.size() - 1; i >= 0; i--) st.push(input[i]);

    reverseStack(st);
    printStack(st);

    return 0;
}

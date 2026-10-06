#include <iostream>
#include <string>
#include <stack>

using namespace std;

int minAddToMakeValid(string s) {
    stack<char> st;
    int open_needed = 0;

    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else { // c == ')'
            if (!st.empty()) {
                st.pop();
            } else {
                open_needed++;
            }
        }
    }

    return open_needed + st.size();
}
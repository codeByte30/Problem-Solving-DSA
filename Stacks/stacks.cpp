#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool isBalanced(string s) {
    int n = s.length();
    stack<char>st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' or s[i] == '[' or s[i] == '{') {
            st.push(s[i]);
        }
        else {
            if (s[i] == ')') {
                if (!st.empty() and st.top() == '(') {
                    st.pop();
                }
                else {
                    st.push(s[i]);
                }
            }
            else if (s[i] == ']') {
                if (!st.empty() and st.top() == '[') {
                    st.pop();
                }
                else {
                    st.push(s[i]);
                }
            }
            else if (s[i] == '}') {
                if (!st.empty() and st.top() == '{') {
                    st.pop();
                }
                else {
                    st.push(s[i]);
                }
            }
        }
    }

    return st.empty();

}

bool redundantBraces(string s) {
    int n = s.length();
    stack<char>st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' or s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            bool containsOperator = false;

            while (!st.empty() and st.top() != '(') {
                if (st.top() == '+' or st.top() == '-' or st.top() == '*' or st.top() == '/') {
                    containsOperator = true;
                }
                st.pop();
            }

            if (containsOperator == false) {
                return false;
            }
            st.pop();
        }
    }
    return true;
}
vector<int>nextGreaterElement(vector<int>&arr) {
    vector<int>ans;
    int n = arr.size();
    stack<int>st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() and arr[i] >= st.top()) {
            st.pop();
        }

        if (st.empty()) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(st.top());
        }

        st.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int>nextLesserElement(vector<int>&arr) {
    vector<int>ans;
    int n = arr.size();
    stack<int>st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() and arr[i] <= st.top()) {
            st.pop();
        }

        if (st.empty()) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(st.top());
        }

        st.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    // string s;
    // cin >> s;

    // if (isBalanced(s)) {
    //     cout << "Bracket Sequence is balanced";
    // }
    // else {
    //     cout << "Not balanced";
    // }

    // if (redundantBraces(s)) {
    //     cout << "Bracket Sequence do not contain redundant braces";
    // }
    // else {
    //     cout << "Redundant braces";
    // }

    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n ; i++) {
        cin >> arr[i];
    }

    // vector<int>output = nextGreaterElement(arr);
    vector<int>output = nextLesserElement(arr);

    for (auto x : output) {
        cout << x << " ";
    }


    return 0;
}
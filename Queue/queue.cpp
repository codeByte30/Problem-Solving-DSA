#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// void firstNonRepeatingCharacter(string s) {
//     int n = s.length();
//     //char,{index,freq}
//     unordered_map<char, pair<int, int>>m;
//     for (int i = 0; i < s.length(); i++) {
//         //update the map
//         char ch = s[i];
//         if (m.find(ch) != m.end()) {
//             m[ch].second++;
//         }
//         else {
//             m[ch] = {i, 1};
//         }

//         //search
//         int index = INT_MAX;
//         for (auto p : m) {
//             if (p.second.second == 1) {
//                 if (p.second.first < index) {
//                     index = p.second.first;
//                 }
//             }
//         }
//         if (index == INT_MAX) {
//             cout << "-1 ";
//         } else {
//             cout << s[index] << " ";
//         }
//     }
// }

void firstNonRepeatingCharacterOptimised(string s) {
    int n = s.length();
    queue<char>q;
    int freq[256] = {0};
    for (int i = 0; i < n; i++) {
        q.push(s[i]);
        freq[s[i]]++;

        while (!q.empty() and freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) {
            cout << "-1 ";
        }
        else {
            cout << q.front() << " ";
        }
    }
}

void reverseFirstKElements(queue<int>&q, int k) {
    deque<int>Q;
    int n = q.size();
    int temp = k;
    while (temp--) {
        Q.push_back(q.front());
        q.pop();
    }

    while (!Q.empty()) {
        q.push(Q.back());
        Q.pop_back();
    }

    int x = (n - k);
    while (x--) {
        q.push(q.front());
        q.pop();
    }

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
    // firstNonRepeatingCharacterOptimised(s);

    int n = 5, k = 3;
    queue<int>q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    reverseFirstKElements(q, k);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
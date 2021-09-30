#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void longestPalindromicSubstring(string s) {
    int maxLength = 0;
    int start = -1;
    int n = s.length();
    //odd
    for (int i = 0; i < n; i++) {
        maxLength = max(maxLength, 1);
        int left = i - 1, right = i + 1;
        while (left >= 0 and right < n and s[left] == s[right]) {
            int currLength = right - left + 1;
            if (currLength > maxLength) {
                maxLength = currLength;
                start = left;
            }
            left--;
            right++;
        }
    }

    //even
    for (int i = 0; i < n - 1; i++) {
        int left = i, right = i + 1;
        if (s[left] != s[right]) {
            continue;
        }
        else {
            while (left >= 0 and right < n and s[left] == s[right]) {
                int currLength = right - left + 1;
                if (currLength > maxLength) {
                    maxLength = currLength;
                    start = left;
                }
                left--;
                right++;
            }
        }
    }
    cout << start << " " << maxLength << endl;
    cout << s.substr(start, maxLength) << endl;

}
int hashFunction(string s) {
    int hashValue = 0;
    for (int i = 0; i < s.length(); i++) {
        hashValue += (s[i] - 'a');
    }
    return hashValue;
}
void RabinKarpAlgo(string s, string p) {
    int hash_pattern = hashFunction(p);
    int n = s.length();
    int m = p.length();

    string temp = s.substr(0, m);
    int temp_hash = hashFunction(temp);

    if (temp_hash == hash_pattern) {
        if (temp == p) {
            cout << 0 << " ";
        }
    }
    else {
        for (int i = m; i < n; i++) {
            temp_hash = temp_hash - s[i - m] + s[i];
            if (temp_hash == hash_pattern) {
                //possiblity that i have found my pattern
                if (s.substr(i - m + 1, m) == p) {
                    cout << i - m + 1 << " ";
                    // return true;
                }
            }
            continue;
        }
    }

    // return false;

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
    // longestPalindromicSubstring(s);

    ////////////////////////////////////////////


    string str, pattern;
    cin >> str >> pattern;
    // if (RabinKarpAlgo(str, pattern)) {
    //     cout << "Pattern Found in the string";
    // }
    // else
    // {
    //     cout << "Not Found";
    // }

    RabinKarpAlgo(str, pattern);




    return 0;
}
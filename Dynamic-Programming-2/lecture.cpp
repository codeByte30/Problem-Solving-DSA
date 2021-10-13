#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int dp[1001][1001];
int knapSack(int i, int wt[], int val[], int n, int W) {
    if (i >= n) {
        return 0;
    }

    if (W == 0) {
        return 0;
    }

    if (dp[i][W] != -1) {
        return dp[i][W];
    }

    int pick = 0, nonPick = 0;

    if (wt[i] <= W) {
        pick += (val[i] + knapSack(i + 1, wt, val, n, W - wt[i]));
    }

    nonPick += knapSack(i + 1, wt, val, n, W);

    return dp[i][W] = max(pick, nonPick);
}
int UnboundedKnapSack(int i, int wt[], int val[], int n, int W) {
    if (i >= n) {
        return 0;
    }

    if (W == 0) {
        return 0;
    }

    if (dp[i][W] != -1) {
        return dp[i][W];
    }

    int pick = 0, nonPick = 0;

    if (wt[i] <= W) {
        pick += (val[i] + knapSack(i, wt, val, n, W - wt[i]));
    }

    nonPick += knapSack(i + 1, wt, val, n, W);

    return dp[i][W] = max(pick, nonPick);
}

int lcs(int i, int j, string a, string b) {
    //base case
    if (i == a.length() or j == b.length()) {
        return 0;
    }
    //check
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    //recursive case
    if (a[i] == b[j]) {
        return dp[i][j] = 1 + lcs(i + 1, j + 1, a, b);
    }
    else {
        return dp[i][j] = max(lcs(i + 1, j, a, b), lcs(i, j + 1, a, b));
    }
}
int lcsBottomUp(string a, string b) {
    int n = a.length();
    int m = b.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 or j == 0) dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    string ans = "";
    int i = n, j = m;
    while (i > 0 and j > 0) {
        if (a[i - 1] == b[j - 1]) {
            ans += a[i - 1];
            i--; j--;
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return dp[n][m];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    memset(dp, -1, sizeof dp);
    // int n, W;
    // cin >> n >> W;
    // int wt[n], val[n];
    // for (int i = 0; i < n ; i++) {
    //     cin >> wt[i] >> val[i];
    // }





    // cout << knapSack(0, wt, val, n, W);


    string a, b;
    cin >> a >> b;
    cout << lcs(0, 0, a, b) << endl;
    int n = a.length();
    int m = b.length();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    string ans = "";
    int i = 0, j = 0 ;
    while (i < n and j < m) {
        if (a[i] == b[j]) {
            ans += a[i];
            i++; j++;
        }
        else {
            if (dp[i + 1][j] > dp[i][j + 1]) {
                i++;
            }
            else {
                j++;
            }
        }
    }

    cout << ans << endl;
    // cout << lcsBottomUp(a, b) << endl;


    return 0;
}
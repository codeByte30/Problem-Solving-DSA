#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int fibonacciTopDown(int n, int dp[]) {

    if (n == 0) return dp[0] = 0;
    if (n == 1) return dp[1] = 1;

    //check if already calculated
    if (dp[n] != -1) {
        return dp[n];
    }

    int ans = fibonacciTopDown(n - 1, dp) + fibonacciTopDown(n - 2, dp);
    return dp[n] = ans;
}

int fibonacciBottomUp(int n) {
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
int houseRobber(int n, int arr[]) {
    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }
    return dp[n - 1];
}
int countWays(int n) {

    int dp[n + 1];
    dp[1] = 1;
    dp[2] = 2; // 1,1 or 2
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int longestIncSubsequence(int n, int arr[]) {
    vector<int>dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    // int dp[n + 1];
    // for (int i = 1; i <= n; i++) {
    //     dp[i] = -1;
    // }
    // memset(dp, -1, sizeof dp); // 0 and -1
    // cout << fibonacciTopDown(n, dp) << endl;
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << dp[i] << " ";
    // }

    // cout << fibonacciBottomUp(n) << endl;
    int arr[n];
    for (int i = 0; i < n ; i++) {
        cin >> arr[i];
    }
    // cout << houseRobber(n, arr);
    cout << longestIncSubsequence(n, arr);
    return 0;
}
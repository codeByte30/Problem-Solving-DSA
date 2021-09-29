#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n ; i++) {
    //     cin >> arr[i];
    // }

    // int sum;
    // cin >> sum;
    // sort(arr, arr + n);
    // int left = 0, right = n - 1;
    // while (left < right) {
    //     if (arr[left] + arr[right] == sum)
    //     {
    //         cout << arr[left] << " " << arr[right] << endl;
    //         left++;
    //         right--;
    //     }
    //     else if (arr[left] + arr[right] < sum) {
    //         left++;
    //     }
    //     else {
    //         right--;
    //     }
    // }


    // ----------------------------------------------------

    // int n;
    // cin >> n;
    // vector<vector<int>>mat(n, vector<int>(n));
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cin >> mat[i][j];
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (mat[i][j] == 0) {

    //             //up
    //             int row = i - 1, col = j;
    //             while (row >= 0) {
    //                 mat[row][col] = -1;
    //                 row--;
    //             }
    //             //down
    //             row = i + 1, col = j;
    //             while (row < n) {
    //                 mat[row][col] = -1;
    //                 row++;
    //             }

    //             //left
    //             row = i, col = j - 1;
    //             while (col >= 0) {
    //                 mat[row][col] = -1;
    //                 col--;
    //             }

    //             //right
    //             row = i, col = j + 1;
    //             while (col < n) {
    //                 mat[row][col] = -1;
    //                 col++;
    //             }
    //         }
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (mat[i][j] == -1) {
    //             mat[i][j] = 0;
    //         }
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // .-----------------------------------------

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n ; i++) {
        cin >> arr[i];
    }
    // int start = -1, end = -1;
    // int ans = INT_MIN;
    // for (int i = 0; i < n; i++) {
    //     for (int j = i; j < n; j++) {
    //         int curr_sum = 0;
    //         for (int k = i; k <= j; k++) {
    //             curr_sum += arr[k];
    //         }
    //         if (curr_sum > ans) {
    //             ans = curr_sum;
    //             start = i;
    //             end = j;
    //         }
    //     }
    // }
    // cout << ans << endl;
    // for (int i = start; i <= end; i++) {
    //     cout << arr[i] << " ";
    // }
    // vector<int>prefixSum(n);
    // for (int i = 0; i < n; i++) {
    //     if (i == 0) {
    //         prefixSum[i] = arr[i];
    //     }
    //     else {
    //         prefixSum[i] = prefixSum[i - 1] + arr[i];
    //     }
    // }
    // int ans = INT_MIN;

    // for (int i = 0; i < n; i++) {
    //     int curr_ans = prefixSum[i];
    //     for (int j = 1; j < i; j++) {
    //         curr_ans = max(curr_ans, prefixSum[i] - prefixSum[j - 1]);
    //     }
    //     ans = max(ans, curr_ans);
    // }
    // cout << ans << endl;

    // ---------------------------/


    int maxSum = INT_MIN, currSum = 0, count = 0, max_ele = INT_MIN;
    for (int i = 0; i < n ; i++) {
        currSum += arr[i];
        if (currSum < 0) {
            currSum = 0;
        }
        if (arr[i] < 0) {
            count++;
            max_ele = max(max_ele, arr[i]);
        }
        maxSum = max(maxSum, currSum);
    }
    if (count == n) {
        cout << max_ele << endl;
    }
    else {
        cout << maxSum << endl;
    }

    return 0;
}
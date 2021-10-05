#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void print1toN(int n) {
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    print1toN(n - 1);
    cout << n << endl;
}
void printNto1(int n) {
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    cout << n << endl;
    printNto1(n - 1);
}
int numberOfWaysToreachEnd(int i, int j, int n, int m) {
    if (i >= n or j >= m) {
        return 0;
    }

    if (i == n - 1 and j == m - 1) {
        return 1;
    }

    return numberOfWaysToreachEnd(i + 1, j, n, m) + numberOfWaysToreachEnd(i, j + 1, n, m);
}

int friendsPairing(int n) {
    if (n == 1) {
        return 1;
    }

    if (n == 2) {
        return 2;
    }


    return friendsPairing(n - 1) + (n - 1) * friendsPairing(n - 2);
}

void solve(int i, vector<int>&arr, int target, vector<int>&v, vector<vector<int>>&ans) {
    //base case
    if(i == arr.size()){
        if(target == 0){
            ans.push_back(v);
        }
        return;
    }

    //pick
    if (arr[i] <= target) {
        v.push_back(arr[i]);
        solve(i, arr, target - arr[i], v, ans);
        //backtracking
        v.pop_back();
    }

    //non pick
    solve(i + 1, arr, target, v, ans);
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    vector<vector<int>>ans;
    vector<int>v;
    solve(0, arr, target, v, ans);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // int n;
    // cin >> n;
    // print1toN(n);
    // printNto1(n);
    ///////////////////////////
    // int n, m;
    // cin >> n >> m;
    // cout << numberOfWaysToreachEnd(0, 0, n, m);
    //////////////

    int n;
    cin >> n;
    cout << friendsPairing(n) << endl;



    return 0;
}
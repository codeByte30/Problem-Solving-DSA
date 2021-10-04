#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// int squareRoot(int n) {
//     int ans = -1;
//     int low = 1, high = n;
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (mid * mid <= n) {
//             ans = mid;
//             low = mid + 1;
//         }
//         else {
//             high = mid - 1;
//         }
//     }
//     return ans;
// }
bool possible(ll positions[], ll n, ll c, ll mid)
{
    ll count = 1;
    ll last_pos = positions[0];
    for (int i = 1; i < n; i++)
    {
        if (positions[i] - last_pos >= mid)
        {
            count++;
            if (count == c)
            {
                return true;
            }
            last_pos = positions[i];
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // int n;
    // cin >> n;
    // cout << squareRoot(n) << endl;

    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        ll positions[n];
        for (int i = 0; i < n; i++)
        {
            cin >> positions[i];
        }
        sort(positions, positions + n);
        ll low = 0, high = (positions[n - 1] - positions[0]);
        ll ans = -1;
        while (low <= high)
        {
            ll mid = (high + low) / 2;
            if (possible(positions, n, c, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
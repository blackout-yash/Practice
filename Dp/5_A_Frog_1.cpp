// A - Frog 1
// Link - https://atcoder.jp/contests/dp/tasks/dp_a



#include <bits/stdc++.h>
using namespace std;
#define ll int
#define fora(a,b) for(ll i=a;i<b;i++)


// Bottom Up
int minCost1(int h[], int n, vector <int> &dp) {
    if (n == 0 || n == 1) return 0;
    if (dp[n] != -1) return dp[n];

    int ans1 = INT_MAX;
    if (n > 2) ans1 = abs(h[0] - h[2]) + minCost1(h + 2, n - 2, dp);
    int ans2 = abs(h[0] - h[1]) + minCost1(h + 1, n - 1, dp);

    return dp[n] = min(ans1, ans2);
}


// Top Down
int minCost2(int h[], int n) {
    int dp[n + 1];
    dp[0] = dp[1] = 0;
    for (int i = 2; i < n + 1; ++i) {
        if (i == 2) dp[i] = abs(h[i - 1] - h[i - 2]);
        else dp[i] = min(abs(h[i - 1] - h[i - 2]) + dp[i - 1], abs(h[i - 1] - h[i - 3]) + dp[i - 2]);
    }
    return dp[n];
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int h[n];
    fora(0, n) cin >> h[i];

    vector <int> dp(n + 1, -1);
    cout << minCost1(h, n, dp) << " " << minCost2(h, n);
    return 0;
}
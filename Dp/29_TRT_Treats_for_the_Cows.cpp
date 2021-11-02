// TRT - Treats for the Cows
// Link - https://www.spoj.com/problems/TRT/



#include <iostream>
#include <vector>
using namespace std;
#define int long long


int solve(int v[], int i, int j, int day, vector <vector <int>> &dp) {
    if (i > j) return 0;
    else if (dp[i][j] != -1) return dp[i][j];

    int ans1 = v[i] * day + solve(v, i + 1, j, day + 1, dp);
    int ans2 = v[j] * day + solve(v, i, j - 1, day + 1, dp);

    return dp[i][j] = max(ans1, ans2);
}


// Top Down
int maximumRevenue1(int v[], int n) {
    vector <vector <int>> dp(n + 1, vector <int> (n + 1, -1));
    return solve(v, 0, n - 1, 1, dp);
}


// Bottom Up
int maximumRevenue2(int v[], int n) {
    int dp[n][n], days = 1;
    for (int i = n - 1; i >= 0 ; --i) {
        for (int j = 0; j < n; ++j) {
            int days = i + (n - j);
            if (i > j) dp[i][j] = 0;
            else if (i == j) dp[i][j] = v[i] * days;
            else {
                int ans1 = v[i] * days + dp[i + 1][j];
                int ans2 = v[j] * days + dp[i][j - 1];

                dp[i][j] = max(ans1, ans2);
            }
        }
    }
    return dp[0][n - 1];
}


int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int v[n];
        for (int i = 0; i < n; ++i) cin >> v[i];

        cout << maximumRevenue1(v, n) << " " << maximumRevenue2(v, n) << "\n";
    }

    return 0;
}
// Perfect Sum Problem
// Link - https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1



#include <iostream>
#include <vector>

using namespace std;

int solve(int arr[], int n, int sum, vector<vector <long long>> &dp) {
    if (sum == 0) return 1;
    else if (n == 0) return 0;
    else if (dp[n][sum] != -1) return dp[n][sum];

    long long ans1 = 0;
    if (sum >= arr[n - 1]) ans1 = solve(arr, n - 1, sum - arr[n - 1], dp);
    long long ans2 = solve(arr, n - 1, sum, dp);

    long long mod = (1e9) + 7;
    return dp[n][sum] = (ans1 % mod + ans2 % mod) % mod;
}

int perfectSum1(int arr[], int n, int sum) {
    vector <vector <long long>> dp(n + 1, vector <long long> (sum + 1, -1));
    return solve(arr, n, sum, dp);
}



int perfectSum2(int arr[], int N, int sum) {
    long long dp[N + 1][sum + 1], mod = (1e9) + 7;

    for (long long i = 0; i < N + 1; ++i) {
        for (long long j = 0; j < sum + 1; ++j) {

            if (j == 0) dp[i][j] = 1;
            else if (i == 0) dp[i][j] = 0;
            else {
                long long ans1 = 0;
                if (j >= arr[i - 1]) ans1 = dp[i - 1][j - arr[i - 1]];
                long long ans2 = dp[i - 1][j];

                dp[i][j] = (ans1 % mod + ans2 % mod) % mod;
            }
        }
    }
    return dp[N][sum];
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, sum;
        cin >> n >> sum;
        int arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];

        cout << perfectSum1(arr, n, sum) << " " << perfectSum2(arr, n, sum) << "\n";
    }

    return 0;
}
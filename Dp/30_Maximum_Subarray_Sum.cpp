// Maximum Subarray Sum
// Link - https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1#



#include <iostream>
#include <vector>
using namespace std;


long long solve(int arr[], int n, long long &maximum, vector <long long> &dp) {
    if (n == 0) return 0;
    else if (dp[n] != -1) return dp[n];

    long long ans = max((long long)arr[n - 1], arr[n - 1] + solve(arr, n - 1, maximum, dp));
    maximum = max(maximum, ans);

    return dp[n] = ans;
}


// Top Down
long long maxSubarraySum1(int arr[], int n) {
    vector <long long> dp(n + 1, -1);
    long long maximum = INT_MIN;
    solve(arr, n, maximum, dp);

    return maximum;
}


// Bottom Up
long long maxSubarraySum2(int arr[], int n) {
    long long dp[n + 1], maximum = INT_MIN;

    for (int i = 0; i < n + 1; ++i) {
        if (i == 0) dp[i] = 0;
        else {
            long long ans = max((long long)arr[i - 1], arr[i - 1] + dp[i - 1]);
            dp[i] = ans;
            maximum = max(maximum, ans);
        }
    }
    return maximum;
}


int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];

        cout << maxSubarraySum1(arr, n) << " " << maxSubarraySum2(arr, n) << "\n";
    }
    return 0;
}
// Count ways to reach the n'th stair
// Link - https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1#



#include <iostream>
#include <vector>
using namespace std;
const long long mod = 1e9 + 7;


long long solve(int n, vector <long long> &dp) {
    if (n == 0) return 1;
    else if (n < 0) return 0;
    else if (dp[n] != -1) return dp[n];

    long long ans1 = solve(n - 1, dp);
    long long ans2 = solve(n - 2, dp);

    return dp[n] = (ans1 % mod + ans2 % mod) % mod;
}


// Top Down
int countWays1(int n) {
    vector <long long> dp(n + 1, - 1);
    return solve(n, dp);
}


// Bottom Up
int countWays2(int n) {
    long long dp[n + 1];

    for (long long i = 0; i < n + 1; ++i) {
        if (i == 0) dp[i] = 1;
        else {
            long long ans1, ans2 = 0;
            ans1 = dp[i - 1];
            if (i > 1) ans2 = dp[i - 2];

            dp[i] = (ans1 % mod + ans2 % mod) % mod;
        }
    }
    return dp[n];
}



// Bottom Up (Space Optimized)
int countWays3(int n) {
    long long first_last, second_last;

    for (long long i = 0; i < n + 1; ++i) {
        if (i == 0) first_last = 1;
        else {
            long long ans1, ans2 = 0;
            ans1 = first_last;
            if (i > 1) ans2 = second_last;

            second_last = first_last;
            first_last = (ans1 % mod + ans2 % mod) % mod;;
        }
    }
    return first_last;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << countWays1(n) << " " << countWays2(n) << " " << countWays3(n) << "\n";
    }

    return 0;
}
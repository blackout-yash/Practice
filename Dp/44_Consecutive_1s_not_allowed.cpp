// Consecutive 1's not allowed
// Link - https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1



#include <iostream>
#include <vector>
const int mod = 1e9 + 7;
using namespace std;


long long solve(int n, int one, vector <vector <long long>> &dp) {
	if (n == 1) {
		if (one) return 1;
		return 2;
	} else if (dp[n][one] != -1) return dp[n][one];


	long long ans1 = 0;
	if (one == 0) ans1 = solve(n - 1, 1, dp);
	long long ans2 = solve(n - 1, 0, dp);

	return dp[n][one] = (ans1 % mod + ans2 % mod) % mod;
}


// Top Down
long long countStrings1(int n) {
	vector <vector <long long>> dp(n + 1, vector <long long> (2, -1));
	return solve(n, 0, dp);
}


// Bottom Up
long long countStrings2(int n) {
	long long dp[n];

	long long zero = 1, one = 1;
	for (int i = 1; i < n + 1; ++i) {
		dp[i] = (zero % mod + one % mod) % mod;
		long long temp = zero;
		zero = (zero % mod + one % mod) % mod;
		one = temp;
	}
	return dp[n];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << countStrings1(n) << " " << countStrings2(n) << "\n";
	}

	return 0;
}
// Nth Fibonacci Number
// Link - https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1#



#include <iostream>
#include <vector>
const long long mod = 1000000007;

using namespace std;


long long int solve(long long n, vector <long long int> &dp) {
	if (n == 0 || n == 1) return n;
	else if (dp[n] != -1) return dp[n];

	return dp[n] = (solve(n - 1, dp) % mod + solve(n - 2, dp) % mod) % mod;
}


// Top Down
long long int nthFibonacci1(long long int n) {
	vector <long long int> dp(n + 1, -1);
	return solve(n, dp);
}


// Bottom Up
long long int nthFibonacci2(long long int n) {
	long long int dp[n + 1];
	for (int i = 0; i < n + 1; ++i) {
		if (i == 0 || i == 1) dp[i] = i;
		else dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
	}
	return dp[n];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << nthFibonacci1(n) << " " << nthFibonacci2(n) << "\n";
	}
	return 0;
}
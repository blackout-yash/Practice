// Coin Change
// Link - https://practice.geeksforgeeks.org/problems/coin-change2448/1#



#include <iostream>
#include <vector>

using namespace std;


long solve(int S[], int m, int n, vector <vector <long long>> &dp) {
	if (n == 0) return 1;
	else if (m == 0) return 0;
	else if (dp[m][n] != -1) return dp[m][n];

	long long ans1 = 0;
	if (S[m - 1] <= n) ans1 = solve(S, m, n - S[m - 1], dp);

	long long ans2 = solve(S, m - 1, n, dp);

	return dp[m][n] = ans1 + ans2;
}


// Top Down
long long int count1(int S[], int m, int n) {
	vector <vector <long long>> dp(m + 1, vector<long long> (n + 1, -1));
	return solve(S, m, n, dp);
}


// Bottom Up
long long int count2(int S[], int m, int n) {
	long long int dp[m + 1][n + 1];

	for (int i = 0; i < m + 1; ++i) {
		for (int j = 0; j < n + 1; ++j) {
			if (j == 0) dp[i][j] = 1;
			else if (i == 0) dp[i][j] = 0;
			else {
				long long ans1 = 0;
				if (j >= S[i - 1]) ans1 = dp[i][j - S[i - 1]];
				long long ans2 = dp[i - 1][j];

				dp[i][j] = ans1 + ans2;
			}
		}
	}
	return dp[m][n];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m;
		int S[m];
		for (int i = 0; i < m; ++i) cin >> S[i];
		cin >> n;

		cout << count1(S, m, n) << " " << count2(S, m, n) << "\n";
	}
	return 0;
}
// Unique Paths
// Link - https://leetcode.com/problems/unique-paths/



#include <iostream>
#include <vector>
using namespace std;

int solve(int m, int n, vector <vector <int>> &dp) {
	if (m == 1 || n == 1) return dp[m][n] = 1;
	else if (dp[m][n] != -1) return dp[m][n];

	return dp[m][n] = solve(m - 1, n, dp) + solve(m, n - 1, dp);
}


// Top Down
int uniquePaths1(int m, int n) {
	vector <vector <int>> dp(m + 1, vector <int> (n + 1, -1));
	return solve(m, n, dp);
}


// Bottom Up
int uniquePaths2(int m, int n) {
	int dp[m][n];

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == 0 || j == 0) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		cout << uniquePaths1(m, n) << " " << uniquePaths2(m, n) << "\n";
	}

	return 0;
}
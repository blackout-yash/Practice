// Shortest Common Supersequence
// Link - https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1



#include <iostream>
#include <vector>

using namespace std;


int solve(string &X, string &Y, int m, int n, vector<vector<int>> &dp) {
	if (m == 0 || n == 0) return 0;
	else if (dp[m][n] != -1) return dp[m][n];

	int ans;
	if (X[m - 1] == Y[n - 1]) ans = 1 + solve(X, Y, m - 1, n - 1, dp);
	else ans = max(solve(X, Y, m - 1, n, dp), solve(X, Y, m, n - 1, dp));

	return dp[m][n] = ans;
}


// Top Down
int shortestCommonSupersequence1(string X, string Y, int m, int n) {
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
	return m + n - solve(X, Y, m, n, dp);
}


// Bottom Up
int shortestCommonSupersequence2(string X, string Y, int m, int n) {
	int dp[m + 1][n + 1];

	for (int i = 0; i < m + 1; ++i) {
		for (int j = 0; j < n + 1; ++j) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else {
				int ans;
				if (X[i - 1] == Y[j - 1]) ans = 1 + dp[i - 1][j - 1];
				else ans = max(dp[i][j - 1], dp[i - 1][j]);

				dp[i][j] = ans;
			}
		}
	}
	return m + n - dp[m][n];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		string X, Y;
		cin >> X >> Y;
		cout << shortestCommonSupersequence1(X, Y, X.size(), Y.size()) << " " << shortestCommonSupersequence2(X, Y, X.size(), Y.size()) << "\n";
	}
	return 0;
}
// Is Subsequence
// Link - https://leetcode.com/problems/is-subsequence/



#include <iostream>
#include <vector>

using namespace std;


int solve(string &A, string &B, int n, int m, vector <vector <int>> &dp) {
	if (n == 0 || m == 0) return 0;
	else if (dp[n][m] != -1) return dp[n][m];

	int ans;
	if (A[n - 1] == B[m - 1]) ans = 1 + solve(A, B, n - 1, m - 1, dp);
	else ans = max(solve(A, B, n - 1, m, dp), solve(A, B, n, m - 1, dp));

	return dp[n][m] = ans;
}


// Top Down
bool isSubsequence1(string A, string B) {
	int n = A.size(), m = B.size();
	vector <vector <int>> dp(n + 1, vector <int>(m + 1, -1));

	if (n == solve(A, B, n, m, dp)) return true;
	return false;
}


// Bottom Up
bool isSubsequence2(string A, string B) {
	int n = A.size(), m = B.size();
	int dp[n + 1][m + 1];
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m + 1; ++j) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else if (A[i - 1] == B[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	if (n == dp[n][m]) return true;
	return false;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		string A, B;
		cin >> A >> B;

		cout << isSubsequence1(A, B) << " " << isSubsequence2(A, B) << "\n";
	}

	return 0;
}
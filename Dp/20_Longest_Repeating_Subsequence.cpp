// Longest Repeating Subsequence
// Link - https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#



#include <iostream>
#include <vector>

using namespace std;


int solve(string &str1, string &str2, int n, int m, vector <vector <int>> &dp) {
	if (n == 0 || m == 0) return 0;
	else if (dp[n][m] != -1) return dp[n][m];

	int ans;
	if (str1[n - 1] == str2[m - 1] && n != m) ans = 1 + solve(str1, str2, n - 1, m - 1, dp);
	else ans = max(solve(str1, str2, n - 1, m, dp), solve(str1, str2, n, m - 1, dp));

	return dp[n][m] = ans;
}


// Top Down
int LongestRepeatingSubsequence1(string str) {
	string str1 = str, str2 = str;
	int n = str1.size(), m = str2.size();

	vector <vector <int>> dp(n + 1, vector <int> (m + 1, -1));

	return solve(str1, str2, n, m, dp);
}


// Bottom Up
int LongestRepeatingSubsequence2(string str) {
	string str1 = str, str2 = str;
	int n = str1.size(), m = str2.size();

	int dp[n + 1][m + 1];

	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < m + 1; ++j) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else {
				int ans;

				if (str1[i - 1] == str2[j - 1] && i != j) ans = 1 + dp[i - 1][j - 1];
				else ans = max(dp[i - 1][j], dp[i][j - 1]);

				dp[i][j] = ans;
			}
		}
	}
	return dp[n][m];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;

		cout << LongestRepeatingSubsequence1(str) << " " << LongestRepeatingSubsequence2(str) << "\n";
	}

	return 0;
}
// Longest Common Substring
// Link - https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1#



#include <iostream>
#include <vector>

using namespace std;


// Top Down
int solve(string &S1, string &S2, int n, int m, int &maximum, vector <vector <int>> &dp) {
	if (n == 0 || m == 0) return 0;
	else if (dp[n][m] != -1) return dp[n][m];

	int ans;
	if (S1[n - 1] == S2[m - 1]) ans = 1 + solve(S1, S2, n - 1, m - 1, maximum, dp);
	else ans = 0;

	solve(S1, S2, n - 1, m, maximum, dp);
	solve(S1, S2, n, m - 1, maximum, dp);

	maximum = max(maximum, ans);
	return dp[n][m] = ans;
}

int longestCommonSubstr1 (string S1, string S2, int n, int m) {
	vector <vector <int>> dp(n + 1, vector <int> (m + 1, -1));
	int maximum = 0;
	solve(S1, S2, n, m, maximum, dp);
	return maximum;
}


// Bottom Up
int longestCommonSubstr2 (string S1, string S2, int n, int m) {
	int dp[n + 1][m + 1], maximum = 0;
	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < m + 1; ++j) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else {
				int ans;

				if (S1[i - 1] == S2[j - 1]) ans = dp[i - 1][j - 1] + 1;
				else ans = 0;

				dp[i][j] = ans;
				maximum = max(maximum, ans);
			}
		}
	}
	return maximum;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		string s1, s2;
		cin >> n >> m >> s1 >> s2;
		cout << longestCommonSubstr1(s1, s2, n, m) << " " << longestCommonSubstr2(s1, s2, n, m) << "\n";
	}

	return 0;
}
// Longest Common Subsequence
// Link - https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1#



#include <iostream>
#include <vector>

using namespace std;


int solve(int x, int y, string &s1, string &s2, vector <vector <int>> &dp) {
	if (x == 0 || y == 0) return 0;
	else if (dp[x][y] != -1) return dp[x][y];


	int maximum;
	if (s1[x - 1] == s2[y - 1]) maximum = 1 + solve(x - 1, y - 1, s1, s2, dp);
	else maximum = max(solve(x, y - 1, s1, s2, dp), solve(x - 1, y, s1, s2, dp));

	return dp[x][y] = maximum;
}

// Top Down
int lcs1(int x, int y, string s1, string s2) {
	vector <vector <int>> dp(x + 1, vector <int> (y + 1, -1));
	return solve(x, y, s1, s2, dp);
}


// Bottom Up
int lcs2(int x, int y, string s1, string s2) {
	int dp[x + 1][y + 1];
	for (int i = 0; i < x + 1; i++) {
		for (int j = 0; j < y + 1; ++j) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	return dp[x][y];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y; string s1, s2;
		cin >> x >> y >> s1 >> s2;

		cout << lcs1(x, y, s1, s2) << " " << lcs2(x, y, s1, s2) << "\n";
	}

	return 0;
}
// The Longest Common Subsequence
// Link - https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem?isFullScreen=false



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solve(vector<int> &a, vector<int> &b, int n, int m, vector <vector <int>> &dp) {
	if (n == 0 || m == 0) return 0;
	else if (dp[n][m] != -1) return dp[n][m];

	int ans;
	if (a[n - 1] == b[m - 1]) ans = 1 + solve(a, b, n - 1, m - 1, dp);
	else ans = max(solve(a, b, n - 1, m, dp), solve(a, b, n, m - 1, dp));

	return dp[n][m] = ans;
}


// Top Down
vector<int> longestCommonSubsequence1(vector<int> a, vector<int> b) {
	int n = a.size(), m = b.size();

	vector <vector <int>> dp(n + 1, vector <int> (m + 1, -1));

	solve(a, b, n, m, dp);

	vector <int> ans;
	int i = n, j = m;
	while (!(i == 0 || j == 0)) {
		if (a[i - 1] == b[j - 1]) {
			ans.push_back(a[i - 1]);
			i--; j--;
		} else if (dp[i - 1][j] > dp[i][j - 1]) i--;
		else j--;
	}
	reverse(ans.begin(), ans.end());

	return ans;
}


// Bottom Up
vector<int> longestCommonSubsequence2(vector<int> a, vector<int> b) {
	int n = a.size(), m = b.size();

	int dp[n + 1][m + 1];
	vector <int> ans;

	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < m + 1; ++j) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else {
				int ans;

				if (a[i - 1] == b[j - 1]) ans = 1 + dp[i - 1][j - 1];
				else ans = max(dp[i - 1][j], dp[i][j - 1]);

				dp[i][j] = ans;
			}
		}
	}

	int i = n, j = m;
	while (!(i == 0 || j == 0)) {
		if (a[i - 1] == b[j - 1]) {
			ans.push_back(a[i - 1]);
			i--; j--;
		} else if (dp[i - 1][j] > dp[i][j - 1]) i--;
		else j--;
	}
	reverse(ans.begin(), ans.end());

	return ans;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector <int> a(n), b(m);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < m; ++i) cin >> b[i];

		vector <int> ans1 = longestCommonSubsequence1(a, b);
		for (auto x : ans1) cout << x;
		cout << " ";

		vector <int> ans2 = longestCommonSubsequence2(a, b);
		for (auto x : ans2) cout << x;
		cout << "\n";
	}

	return 0;
}
// Shortest Common Supersequence
// Ḷink - https://leetcode.com/problems/shortest-common-supersequence/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solve(string &str1, string &str2, int n, int m, vector <vector <int>> &dp) {
	if (n == 0 || m == 0) return 0;
	else if (dp[n][m] != 0) return dp[n][m];

	int ans;
	if (str1[n - 1] == str2[m - 1]) ans = 1 + solve(str1, str2, n - 1, m - 1, dp);
	else ans = max(solve(str1, str2, n - 1, m, dp), solve(str1, str2, n, m - 1, dp));

	return dp[n][m] = ans;
}


// Top Down
string shortestCommonSupersequence1(string str1, string str2) {
	int n = str1.size(), m = str2.size();

	vector <vector <int>> dp(n + 1, vector <int> (m + 1, 0));

	solve(str1, str2, n, m, dp);

	string ans;
	int i = n, j = m;
	while (!(i == 0 || j == 0)) {
		if (str1[i - 1] == str2[j - 1]) {
			ans.push_back(str1[i - 1]);
			i--; j--;
		} else if (dp[i - 1][j] > dp[i][j - 1]) {
			ans.push_back(str1[i - 1]);
			i--;
		} else {
			ans.push_back(str2[j - 1]);
			j--;
		}
	}

	while (i > 0) {
		ans.push_back(str1[i - 1]);
		i--;
	}

	while (j > 0) {
		ans.push_back(str2[j - 1]);
		j--;
	}
	reverse(ans.begin(), ans.end());

	return ans;
}


// Bottom Up
string shortestCommonSupersequence2(string str1, string str2) {
	int n = str1.size(), m = str2.size();

	int dp[n + 1][m + 1];

	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < m + 1; ++j) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else {
				int ans;

				if (str1[i - 1] == str2[j - 1]) ans = 1 + dp[i - 1][j - 1];
				else ans = max(dp[i - 1][j], dp[i][j - 1]);

				dp[i][j] = ans;
			}
		}
	}

	string ans;
	int i = n, j = m;
	while (!(i == 0 || j == 0)) {
		if (str1[i - 1] == str2[j - 1]) {
			ans.push_back(str1[i - 1]);
			i--; j--;
		} else if (dp[i - 1][j] > dp[i][j - 1]) {
			ans.push_back(str1[i - 1]);
			i--;
		} else {
			ans.push_back(str2[j - 1]);
			j--;
		}
	}

	while (i > 0) {
		ans.push_back(str1[i - 1]);
		i--;
	}

	while (j > 0) {
		ans.push_back(str2[j - 1]);
		j--;
	}
	reverse(ans.begin(), ans.end());

	return ans;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		string str1, str2;
		cin >> str1 >> str2;

		cout << shortestCommonSupersequence1(str1, str2) << " " << shortestCommonSupersequence2(str1, str2) << "\n";
	}

	return 0;
}
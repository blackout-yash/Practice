// Scramble String
// Link - https://leetcode.com/problems/scramble-string/



#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;


bool solve(string s1, string s2, unordered_map <string, bool> &dp) {
	if (s1 == s2) return true;
	else if (s1.size() != s2.size()) return false;
	else if (dp.find(s1 + s2) != dp.end()) return dp[s1 + s2];

	int n = s1.size();
	bool ans = false;
	for (int i = 1; i < n; i++) {
		bool ans1 = false, ans2 = false;

		if (solve(s1.substr(0, i), s2.substr(n - i, i), dp) && solve(s1.substr(i, n - i), s2.substr(0, n - i), dp)) ans1 = true;
		else if (solve(s1.substr(0, i), s2.substr(0, i), dp) && solve(s1.substr(i, n - i), s2.substr(i, n - i), dp)) ans2 = true;

		if (ans1 || ans2) {
			ans = true;
			break;
		}
	}
	return dp[s1 + s2] = ans;
}


// Top Down
bool isScramble1(string s1, string s2) {
	unordered_map <string, bool> dp;
	return solve(s1, s2, dp);
}


// Bottom Up
bool isScramble2(string s1, string s2) {
	if (s1.size() != s2.size()) return false;

	int n = s1.size();
	bool dp[n][n][n + 1];
	memset(dp, false, sizeof(dp));

	for (int len = 1; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			for (int j = 0; j <= n - len; j++) {
				if (len == 1) {
					dp[i][j][len] = (s1[i] == s2[j]);
				} else {
					bool flag = false;
					for (int k = 1; k < len; k++) {
						bool ans1 = false, ans2 = false;

						if ((dp[i][j][k] && dp[i + k][j + k][len - k])) ans1 = true;
						else if ((dp[i][j + len - k][k] && dp[i + k][j][len - k])) ans2 = true;

						if (ans1 || ans2) {
							flag = true;
							break;
						}

					} dp[i][j][len] = flag;
				}
			}
		}
	}
	return dp[0][0][n];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;
		cout << isScramble1(s1, s2) << " " << isScramble2(s1, s2) << "\n";
	}

	return 0;
}
// Palindrome Substring Queries
// Link - https://www.geeksforgeeks.org/palindrome-substring-queries/



/*
Sample Input:
2
abbac
2
0 3
1 3
abaaabaaaba
4
0 10
5 8
2 5
5 9

Sample Output:
Yes
No
Yes
No
No
Yes
*/


#include <iostream>
#include <vector>
using namespace std;


int solve(string &s, int i, int j, int n, vector <vector <int>> &dp) {
	if (i < 0 || j > n - 1) return 1;
	else if (i == j) return dp[i][j] = 1;
	else if (abs(i - j) == 1)  return dp[i][j] = (s[i] == s[j]);
	else if (i > j) return dp[i][j] = 0;
	else if (dp[i][j] != -1) return dp[i][j];

	int ans = solve(s, i + 1, j - 1, n, dp);
	solve(s, i, j - 1, n, dp);
	solve(s, i + 1, j, n, dp);

	return dp[i][j] = (ans && s[i] == s[j]);
}


// Bottom Up
vector <vector <int>> palindrome1(string &s, int n) {
	vector <vector <int>> dp(n, vector <int> (n, -1));
	solve(s, 0, n - 1, n, dp);
	return dp;
}


// Top Down
vector <vector <bool>> palindrome2(string &s, int n) {
	vector <vector <bool>> dp(n, vector <bool> (n, false));

	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) dp[i][j] = true;
			else if (i < j) {
				if (abs(i - j) > 1) dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
				else dp[i][j] = (s[i] == s[j]);
			}
		}
	}

	return dp;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();

		vector <vector <int>> dp1 = palindrome1(s, n);
		vector <vector <bool>> dp2 = palindrome2(s, n);

		int q;
		cin >> q;
		while (q--) {
			int l, r;
			cin >> l >> r;

			(dp1[l][r]) ? cout << "Yes " : cout << "No ";
			(dp2[l][r]) ? cout << "Yes\n" : cout << "No\n";
		}
	}

	return 0;
}
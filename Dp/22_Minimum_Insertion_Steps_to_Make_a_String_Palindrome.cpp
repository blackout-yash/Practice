// Minimum Insertion Steps to Make a String Palindrome
// Link - https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/



#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


int solve(string &A, string &B, int n, int m, vector <vector <int>> &dp) {
	if (n == 0 || m == 0) return 0;
	else if (dp[n][m] != -1) return dp[n][m];

	int ans;
	if (A[n - 1] == B[m - 1]) ans = 1 + solve(A, B, n - 1, m - 1, dp);
	else ans = max(solve(A, B, n - 1, m, dp), solve(A, B, n, m - 1, dp));

	return dp[n][m] = ans;
}


// Top Bottom
int minInsertions1(string A) {
	string temp = A;
	reverse(A.begin(), A.end());
	string B = A; A = temp;

	int n = A.size(), m = n;

	vector <vector <int>> dp (n + 1, vector<int>(m + 1, -1));

	return n - solve(A, B, n, m, dp);
}


// Bottom Up
int minInsertions2(string A) {
	string temp = A;
	reverse(A.begin(), A.end());
	string B = A; A = temp;

	int n = A.size(), m = n;
	int dp[n + 1][m + 1];

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m + 1; j++) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else {
				int ans;
				if (A[i - 1] == B[j - 1]) ans = 1 + dp[i - 1][j - 1];
				else ans = max(dp[i - 1][j], dp[i][j - 1]);

				dp[i][j] = ans;
			}
		}
	}
	return n - dp[n][m];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		string A;
		cin >> A;

		cout << minInsertions1(A) << " " << minInsertions2(A) << "\n";
	}
	return 0;
}
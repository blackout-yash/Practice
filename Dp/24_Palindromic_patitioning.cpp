// Palindromic patitioning
// Link - https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1#



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool isPalidrome(string &str, int i, int j) {
	string temp2 = str.substr(i, j - i + 1);
	string temp1 = temp2;

	reverse(temp2.begin(), temp2.end());
	if (temp1 == temp2) return true;
	return false;
}


int solve(string &str, int i, int j, vector <vector <int>> &dp) {
	if (i >= j) return 0;
	else if (dp[i][j] != -1) return dp[i][j];
	else if (isPalidrome(str, i, j)) {
		dp[i][j] = 0;
		return 0;
	}

	int minimum = INT_MAX;
	for (int k = i; k < j; k++) {
		minimum = min(minimum, solve(str, i, k, dp) + solve(str, k + 1, j, dp) + 1);
	}
	return dp[i][j] = minimum;
}


// Top Down
int palindromicPartition1(string str) {
	int n = str.size();
	vector <vector <int>> dp(n, vector <int>(n, -1));
	return solve(str, 0, n - 1, dp);
}


// Bottom Up
int palindromicPartition2(string str) {
	int n = str.size(), dp[n][n];

	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < n; ++j) {
			if (i >= j) dp[i][j] = 0;
			else {
				if (isPalidrome(str, i, j)) dp[i][j] = 0;
				else {
					int minimum = INT_MAX;
					for (int k = i; k < j; ++k) {
						minimum = min(minimum, dp[i][k] + dp[k + 1][j] + 1);
					}
					dp[i][j] = minimum;
				}
			}
		}
	}
	return dp[0][n - 1];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;

		cout << palindromicPartition1(str) << " " << palindromicPartition2(str) << "\n";
	}

	return 0;
}

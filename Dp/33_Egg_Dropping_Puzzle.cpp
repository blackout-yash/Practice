// Egg Dropping Puzzle
// Link - https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1#



#include <iostream>
#include <vector>
using namespace std;


int solve(int n, int k, vector <vector <int>> &dp) {
	if (k == 0 || k == 1) return k;
	else if (n == 1) return k;
	else if (dp[n][k] != -1) return dp[n][k];

	int minimum = INT_MAX;
	for (int i = 1; i < k + 1; ++i) {
		int temp = 1 + max(solve(n - 1, i - 1, dp), solve(n, k - i, dp));
		minimum = min(temp, minimum);
	}
	return dp[n][k] = minimum;
}


// Bottom Up
int eggDrop1(int n, int k) {
	vector <vector <int>> dp(n + 1, vector <int> (k + 1, -1));
	return solve(n, k, dp);
}


// Top Bottom
int eggDrop2(int n, int k) {
	int dp[n + 1][k + 1];

	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < k + 1; ++j) {
			if (i == 0) dp[i][j] = 0;
			else if (i == 1) dp[i][j] = j;
			else if (j == 0 || j == 1) dp[i][j] = j;
			else {
				int minimum = INT_MAX;
				for (int l = 1; l < j + 1; ++l) {
					int temp = 1 + max(dp[i - 1][l - 1], dp[i][j - l]);
					minimum = min(temp, minimum);
				}
				dp[i][j] = minimum;
			}
		}
	}

	return dp[n][k];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		cout << eggDrop1(n, k) << " " << eggDrop2(n, k) << "\n";
	}
	return 0;
}
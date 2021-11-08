// 0 - 1 Knapsack Problem
// Link - https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

// D - Knapsack 1
// Link - https://atcoder.jp/contests/dp/tasks/dp_d


// Complexity - O(N*W)



#include <bits/stdc++.h>

using namespace std;

int solve1(int W, int wt[], int val[], int n, vector <vector <int>> &dp) {
	if (W == 0 || n < 0) return 0;
	else if (dp[n][W] != -1) return dp[n][W];

	int ans1 = 0, ans2 = 0;
	if (W >= wt[n])
		ans1 = val[n] + solve1(W - wt[n], wt, val, n - 1, dp);

	ans2 = solve1(W, wt, val, n - 1, dp);

	return dp[n][W] = max(ans1, ans2);
}

// Top Down
int knapSack1(int W, int wt[], int val[], int n) {
	vector <vector <int>> dp(n + 1, vector <int> (W + 1, -1));

	return solve1(W, wt, val, n - 1, dp);
}

// Bottom Up
int knapSack2(int W, int wt[], int val[], int n) {
	int dp[n + 1][W + 1];

	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < W + 1; ++j) {
			int ans1 = 0, ans2 = 0;
			if (i == 0 || j == 0) dp[i][j] = 0;
			else {
				if (j >= wt[i - 1]) ans1 = val[i - 1] + dp[i - 1][j - wt[i - 1]];
				ans2 = dp[i - 1][j];
				dp[i][j] = max(ans1, ans2);
			}
		}
	}
	return dp[n][W];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int w, n;
		cin >> n >> w;
		int wt[n], v[n];
		for (int i = 0; i < n; ++i) cin >> v[i];
		for (int i = 0; i < n; ++i) cin >> wt[i];

		cout << knapSack1(w, wt, v, n) << " " << knapSack2(w, wt, v, n) << "\n";
	}
}

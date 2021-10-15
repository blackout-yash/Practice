// Rod Cutting
// Link - https://practice.geeksforgeeks.org/problems/rod-cutting0840/1



#include <iostream>
#include <vector>

using namespace std;

int solve(int price[], int n, int size, int i, vector <vector <int>> &dp) {
	if (size == 0) return 0;
	else if (i == n) return 0;
	else if (dp[i][size] != -1) return dp[i][size];

	int ans1 = 0;
	if (size >= (i + 1)) ans1 = price[i] + solve(price, n, size - (i + 1), i, dp);
	int ans2 = solve(price, n, size, i + 1, dp);

	return dp[i][size] = max(ans1, ans2);
}

// Bottom Up
int cutRod1(int price[], int n) {
	vector <vector <int>> dp(n + 1, vector<int> (n + 1, -1));
	return solve(price, n, n, 0, dp);
}


// Top Dowm
int cutRod2(int price[], int n) {
	int dp[n + 1][n + 1];

	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < n + 1; ++j) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else {
				int ans1 = 0;
				if (j >= i) ans1 = price[i - 1] + dp[i][j - i];
				int ans2 = dp[i - 1][j];

				dp[i][j] = max(ans1, ans2);
			}
		}
	}
	return dp[n][n];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int price[n];
		for (int i = 0; i < n; ++i) cin >> price[i];

		cout << cutRod1(price, n) << " " << cutRod2(price, n) << "\n";
	}

	return 0;
}
// Number of Coins
// Link - https://practice.geeksforgeeks.org/problems/number-of-coins1824/1



#include <iostream>
#include <vector>

using namespace std;


int solve(int coins[], int M, int V, vector <vector <int>> &dp) {
	if (V == 0) return 0;
	else if (M == 0) return -1;
	else if (dp[M][V] != -2) return dp[M][V];

	int ans1 = -1;
	if (V >= coins[M - 1]) {
		int count = solve(coins, M, V - coins[M - 1], dp);
		if (count != -1) ans1 = 1 + count;
		else ans1 = count;
	}
	int ans2 = solve(coins, M - 1, V, dp);

	if (ans1 == ans2 && ans1 == -1) return dp[M][V] = -1;
	else if (ans1 != -1 && ans2 != -1) return dp[M][V] = min(ans1, ans2);
	return dp[M][V] = (ans1 != -1) ? ans1 : ans2;
}

// Bottom Up
int minCoins1(int coins[], int M, int V) {
	vector <vector <int>> dp(M + 1, vector <int> (V + 1, -2));
	return solve(coins, M, V, dp);
}


// Top Down
int minCoins2(int coins[], int M, int V) {
	int dp[M + 1][V + 1];

	for (int i = 0; i < M + 1; ++i) {
		for (int j = 0; j < V + 1; ++j) {
			if (j == 0) dp[i][j] = 0;
			else if (i == 0) dp[i][j] = -1;
			else {
				int ans1 = -1;
				if (j >= coins[i - 1]) {
					int count = dp[i][j - coins[i - 1]];
					if (count != -1) ans1 = 1 + count;
					else ans1 = count;
				}
				int ans2 = dp[i - 1][j];


				if (ans1 == ans2 && ans1 == -1)  dp[i][j] = -1;
				else if (ans1 != -1 && ans2 != -1)  dp[i][j] = min(ans1, ans2);
				else if (ans1 != -1) dp[i][j] = ans1;
				else dp[i][j] = ans2;
			}
		}
	}
	return dp[M][V];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int V, M;
		cin >> V >> M;
		int coins[M];
		for (int i = 0; i < M; ++i) cin >> coins[i];

		cout << minCoins1(coins, M, V) << " " << minCoins2(coins, M, V) << "\n";
	}

	return 0;
}
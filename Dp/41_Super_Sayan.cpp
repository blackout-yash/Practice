// Super Sayan
// Link - https://www.codechef.com/problems/SSJG



#include <iostream>
#include <vector>
using namespace std;


int calculateMax(vector <vector <int>> &dp) {
	int n = dp.size(), maximum = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int one = dp[i][j];
			int two = dp[i][n - 1] - dp[i][j];
			int three = dp[n - 1][j] - dp[i][j];
			int four = (dp[n - 1][n - 1] + dp[i][j]) - (dp[i][n - 1] + dp[n - 1][j]);

			int minimum = min(one, min(two, min(three, four)));
			maximum = max(maximum, minimum);
		}
	}
	return maximum;
}



int solve(vector <vector <int>> &golds, int i, int j, vector <vector <int>> &dp) {
	if (dp[i][j] != -1) return dp[i][j];

	dp[i][j] = 0;
	if (golds[i][j]) dp[i][j] += 1;

	if (i == 0 && j == 0) return dp[i][j];
	else if (i == 0) return dp[i][j] += solve(golds, i, j - 1, dp);
	else if (j == 0) return dp[i][j] += solve(golds, i - 1, j, dp);

	return dp[i][j] += solve(golds, i - 1, j, dp) + solve(golds, i, j - 1, dp) - solve(golds, i - 1, j - 1, dp);
}


// Top Down
int maxGolds1(vector <vector <int>> &golds, int n) {
	vector <vector <int>> dp(n, vector <int> (n, -1));
	solve(golds, n - 1, n - 1, dp);
	return calculateMax(dp);
}



// Bottom Up
int maxGolds2(vector <vector <int>> &golds, int n) {
	vector <vector <int>> dp(n, vector <int> (n));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == 0 && j == 0) dp[i][j] = 0;
			else if (i == 0) dp[i][j] = dp[i][j - 1];
			else if (j == 0) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

			if (golds[i][j]) dp[i][j] += 1;
		}
	}

	return calculateMax(dp);
}



int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector <vector <int>> golds(n, vector <int> (n, 0));
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			golds[x - 1][y - 1] = 1;
		}

		cout << maxGolds1(golds, n) << " " << maxGolds2(golds, n) << "\n";
	}

	return 0;
}
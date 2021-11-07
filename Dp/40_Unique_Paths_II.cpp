// Unique Paths II
// Link - https://leetcode.com/problems/unique-paths-ii/



#include <iostream>
#include <vector>
using namespace std;


int solve(vector <vector <int>> &obstacleGrid, int m, int n, vector <vector <int>> &dp) {
	if (obstacleGrid[m - 1][n - 1]) return dp[m][n] = 0;
	else if (m == 1 &&  n == 1) return dp[m][n] = 1;
	else if (dp[m][n] != -1) return dp[m][n];
	else if (m == 1) return dp[m][n] = solve(obstacleGrid, m, n - 1, dp);
	else if (n == 1) return dp[m][n] = solve(obstacleGrid, m - 1, n, dp);


	int ans1 = solve(obstacleGrid, m, n - 1, dp);
	int ans2 = solve(obstacleGrid, m - 1, n, dp);


	if (ans1 == 0 && ans2 == 0) return dp[m][n] = 0;
	else if (ans1 == 0) return dp[m][n] = ans2;
	else if (ans2 == 0) return dp[m][n] = ans1;
	return dp[m][n] = ans1 + ans2;
}


// Top Down
int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	vector <vector <int>> dp(m + 1, vector <int> (n + 1, -1));
	return solve(obstacleGrid, m, n, dp);
}


// Bottom Up
int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	int dp[m][n];

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == 0 || j == 0) {
				dp[i][j] = 1;
				if (obstacleGrid[i][j]) dp[i][j] = 0;
				if (i && dp[i - 1][j] == 0) dp[i][j] = 0;
				if (j && dp[i][j - 1] == 0) dp[i][j] = 0;
			}
			else {
				if (obstacleGrid[i][j]) dp[i][j] = 0;
				else {
					int ans1 = dp[i - 1][j];
					int ans2 = dp[i][j - 1];

					if (ans1 == 0 && ans2 == 0) dp[i][j] = 0;
					else if (ans1 == 0) dp[i][j] = ans2;
					else if (ans2 == 0) dp[i][j] = ans1;
					else dp[i][j] = ans1 + ans2;
				}
			}
		}
	}
	return dp[m - 1][n - 1];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		vector <vector <int>> obstacleGrid(m, vector <int> (n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> obstacleGrid[i][j];
			}
		}

		cout << uniquePathsWithObstacles1(obstacleGrid) << " " << uniquePathsWithObstacles2(obstacleGrid) << "\n";
	}

	return 0;
}
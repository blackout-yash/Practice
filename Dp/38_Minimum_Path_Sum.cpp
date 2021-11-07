/*
In this question, movement is allowed only in the right and downward directions.
But, if movement is allowed in all four directions,i.e, left, right, up and down, then this code will not work.
Link of question where left, right, down and up moves are allowed: https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1#
*/


// Minimum Path Sum
// Link - https://leetcode.com/problems/minimum-path-sum/



#include <iostream>
#include <vector>
using namespace std;


int solve(vector <vector <int>> &grid, int m, int n, vector <vector <int>> &dp) {
	if (m == 0 || n == 0) return 0;
	else if (m == 1 && n == 1) return dp[m][n] = grid[m - 1][n - 1];
	else if (dp[m][n] != -1) return dp[m][n];

	if (m != 1 && n != 1) return dp[m][n] = grid[m - 1][n - 1] + min(solve(grid, m - 1, n, dp), solve(grid, m, n - 1, dp));
	else if (m == 1) return dp[m][n] = grid[m - 1][n - 1] + solve(grid, m, n - 1, dp);
	return dp[m][n] = grid[m - 1][n - 1] + solve(grid, m - 1, n, dp);
}


// Top Down
int minimumCostPath1(vector <vector<int>> &grid) {
	int m = grid.size(), n = grid[0].size();
	vector<vector<int>> dp(m + 1, vector <int> (n + 1, -1));
	return solve(grid, m, n, dp);
}


// Bottom Up
int minimumCostPath2(vector<vector<int>>& grid) {
	int m = grid.size(), n = grid[0].size();
	int dp[m][n];

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == 0 && j == 0) dp[i][j] = grid[i][j];
			else if (i == 0) dp[i][j] = grid[i][j] + dp[i][j - 1];
			else if (j == 0) dp[i][j] = grid[i][j] + dp[i - 1][j];
			else {
				dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[m - 1][n - 1];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <vector <int>> grid(n, vector <int> (n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> grid[i][j];
			}
		}

		cout << minimumCostPath1(grid) << " " << minimumCostPath2(grid) << "\n";
	}

	return 0;
}
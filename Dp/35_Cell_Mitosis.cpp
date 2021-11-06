// Cell Mitosis
// Link - https://hack.codingblocks.com/app/contests/1338/546/problem



#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int solve(int n, int x, int y, int z, vector <int> &dp) {
	if (n == 1) return 0;
	else if (dp[n] != -1) return dp[n];

	int cost1 = INT_MAX;
	if (n % 2 == 0) cost1 = x + solve(n / 2, x, y, z, dp);
	else if ((n + 1) % 2 == 0) cost1 = x + z + solve((n + 1) / 2, x, y, z, dp);
	int cost2 = y + solve(n - 1, x, y, z, dp);

	return dp[n] = min(cost1, cost2);
}


// Top Down
int minimumCost1(int n, int x, int y, int z) {
	vector <int> dp(n + 1, -1);
	return solve(n, x, y, z, dp);
}


// Bottom Up
int minimumCost2(int n, int x, int y, int z) {
	int dp[n + 1];

	for (int i = 0; i < n + 1; ++i) {
		if (i == 0 || i == 1) dp[i] = 0;
		else {
			int cost1 = INT_MAX;
			if (i % 2 == 0) cost1 = x + dp[i / 2];
			else if ((i + 1) % 2 == 0) cost1 = x + z + dp[(i + 1) / 2];
			int cost2 = y + dp[i - 1];

			dp[i] = min(cost1, cost2);
		}
	}

	return dp[n];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x, y, z;
		cin >> n >> x >> y >> z;

		cout << minimumCost1(n, x, y, z) << " " << minimumCost2(n, x, y, z) << "\n";
	}
	return 0;
}
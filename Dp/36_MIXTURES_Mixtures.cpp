// MIXTURES - Mixtures
// Link - https://www.spoj.com/problems/MIXTURES/



#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;


int calculate(int arr[], int i, int j) {
	if (i == j) return arr[i];

	int prev = arr[i], ans;
	for (int k = i + 1; k < j + 1; ++k) {
		ans = (prev + arr[k]) % 100;
		prev = ans;
	}
	return ans;
}



int solve(int arr[], int i, int j, vector <vector <int>> &dp) {
	if (i >= j) return 0;
	else if (i + 1 == j) return (arr[i] * arr[j]);
	else if (dp[i][j] != -1) return dp[i][j];

	int ans = INT_MAX;
	for (int k = i; k < j; k++) {
		int ans1 = solve(arr, i, k, dp);
		int ans2 = solve(arr, k + 1, j, dp);

		ans = min(ans, ans1 + ans2 + calculate(arr, i, k) * calculate(arr, k + 1, j));
	}

	return dp[i][j] = ans;
}


// Top Down
int minSmoke1(int arr[], int n) {
	vector <vector <int>> dp(n, vector <int> (n, -1));
	return solve(arr, 0, n - 1, dp);
}



// Bottom Up
int minSmoke2(int arr[], int n) {
	int dp[n][n];
	memset(dp, 0, sizeof(dp));

	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < n; j++) {
			if (i >= j) dp[i][j] = 0;
			else if (i + 1 == j) dp[i][j] = (arr[i] * arr[j]);
			else {
				int ans = INT_MAX;
				for (int k = i; k < j; k++) {
					int ans1 = dp[i][k];
					int ans2 = dp[k + 1][j];

					ans = min(ans, ans1 + ans2 + calculate(arr, i, k) * calculate(arr, k + 1, j));
				} dp[i][j] = ans;
			}
		}
	}
	return dp[0][n - 1];
}



int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int arr[n];
		for (int i = 0; i < n; ++i) cin >> arr[i];

		cout << minSmoke1(arr, n) << " " << minSmoke2(arr, n) << "\n";
	}

	return 0;
}
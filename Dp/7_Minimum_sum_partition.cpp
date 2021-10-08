// Minimum sum partition
// Link - https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1



#include <iostream>
#include <vector>

using namespace std;

int solve(int arr[], int n, int sum, vector <vector <int>> &dp) {
	if (sum == 0) return 1;
	else if (n == 0) return 0;
	else if (dp[n][sum] != -1) return dp[n][sum];

	int ans1 = 0;
	if (sum >= arr[n - 1]) ans1 = solve(arr, n - 1, sum - arr[n - 1], dp);
	int ans2 = solve(arr, n - 1, sum, dp);

	if (ans1 || ans2) dp[n][sum] = 1;
	else dp[n][sum] = 0;

	return dp[n][sum];
}


// Bottom Up
int minDifference1(int arr[], int n)  {
	int sum = 0;
	for (int i = 0; i < n; ++i) sum += arr[i];

	vector <vector <int>> dp(n + 1, vector<int> (sum + 1, -1));

	for (int i = 0; i < sum + 1; ++i) solve(arr, n, i, dp);

	int minimum = sum;
	for (int i = 0; i <= sum / 2; ++i) {
		if (dp[n][i] == 1) minimum = min(minimum, sum - 2 * i);
	}

	return minimum;
}


// Top Down
int minDifference2(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; ++i) sum += arr[i];

	int dp[n + 1][sum + 1];
	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < sum + 1; ++j) {
			if (j == 0) dp[i][j] = 1;
			else if (i == 0) dp[i][j] = 0;
			else {
				int ans1 = 0;
				if (j >= arr[i - 1]) ans1 = dp[i - 1][j - arr[i - 1]];
				int ans2 = dp[i - 1][j];
				if (ans1 || ans2) dp[i][j] = 1;
				else dp[i][j] = 0;
			}
		}
	}

	int minimum = sum;
	for (int i = 0; i <= sum / 2; ++i) {
		if (dp[n][i] == 1) minimum = min(minimum, sum - 2 * i);
	}

	return minimum;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i) cin >> arr[i];

		cout << minDifference1(arr, n) << " " << minDifference2(arr, n) << "\n";
	}

	return 0;
}
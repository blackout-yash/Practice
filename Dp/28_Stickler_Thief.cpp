// Stickler Thief
// Link - https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1



#include <iostream>
#include <vector>

using namespace std;


int solve(int arr[], int n, vector <int> &dp) {
	if (n <= 0) return 0;
	else if (dp[n] != -1) return dp[n];

	int ans1 = arr[n - 1] + solve(arr, n - 2, dp);
	int ans2 = solve(arr, n - 1, dp);

	return dp[n] = max(ans1, ans2);
}


// Top Down
int FindMaxSum1(int arr[], int n) {
	vector <int> dp(n + 1, -1);
	return solve(arr, n, dp);
}


// Bottom Donw
int FindMaxSum2(int arr[], int n) {
	int dp[n + 1];

	for (int i = 0; i < n + 1; ++i) {
		if (i == 0) dp[i] = 0;
		else if (i == 1) dp[i] = arr[i - 1];
		else {
			int ans1 = arr[i - 1] + dp[i - 2];
			int ans2 = dp[i - 1];

			dp[i] = max(ans1, ans2);
		}
	}
	return dp[n];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i) cin >> arr[i];

		cout << FindMaxSum1(arr, n) << " " << FindMaxSum2(arr, n) << "\n";
	}

	return 0;
}
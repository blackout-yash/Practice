// Matrix Chain Multiplication
// Link - practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1



#include <iostream>
#include <vector>

using namespace std;

int solve(int arr[], int i, int j, vector <vector <int>> &dp) {
	if (i >= j) return 0;
	else if (dp[i][j] != -1) return dp[i][j];

	int minimum = INT_MAX;
	for (int k = i; k < j; k++) {
		minimum = min(minimum, solve(arr, i, k, dp) + solve(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j]);
	}
	return dp[i][j] = minimum;
}


// Dp with Memoization
int matrixMultiplication(int N, int arr[]) {
	vector <vector <int>> dp(N - 1, vector <int>(N, -1));
	return solve(arr, 1, N - 1, dp);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i) cin >> arr[i];

		cout << matrixMultiplication(n, arr) << "\n";
	}

	return 0;
}
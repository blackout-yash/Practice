// 				  Subset Sum Problem
// Link - https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#


#include <iostream>
#include <vector>

using namespace std;


bool solve(int N, int arr[], int sum, vector <vector <int>> &dp) {
	if (sum == 0) return true;
	else if (N == 0) return false;
	else if (dp[N][sum] == 1) return true;
	else if (dp[N][sum] == 0) return false;

	bool ans1 = false;
	if (sum >= arr[N - 1]) ans1 = solve(N - 1, arr, sum - arr[N - 1], dp);
	bool ans2 = solve(N - 1, arr, sum, dp);

	if (ans1 || ans2)  return dp[N][sum] = 1;
	return dp[N][sum] = 0;
}

// Bottom Up
bool isSubsetSum1(int N, int arr[], int sum) {
	vector <vector <int>> dp(N + 1, vector <int> (sum + 1, -1));
	return solve(N, arr, sum, dp);
}


// Top Down
bool isSubsetSum2(int N, int arr[], int sum) {
	bool dp[N + 1][sum + 1];

	for (int i = 0; i < N + 1; ++i) {
		for (int j = 0; j < sum + 1; ++j) {

			if (j == 0) dp[i][j] = true;
			else if (i == 0) dp[i][j] = false;
			else {
				bool ans1 = false;
				if (j >= arr[i - 1]) ans1 = dp[i - 1][j - arr[i - 1]];
				bool ans2 = dp[i - 1][j];

				if (ans1 || ans2) dp[i][j] = true;
				else dp[i][j] = false;
			}
		}
	}
	return dp[N][sum];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, sum;
		cin >> n >> sum;
		int arr[n];
		for (int i = 0; i < n; ++i) cin >> arr[i];

		if (isSubsetSum1(n, arr, sum)) cout << "1\t";
		else cout << "0\t";

		if (isSubsetSum2(n, arr, sum)) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}


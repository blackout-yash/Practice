/*
Find number of subsets with given difference.
s1 + s2 = array_sum
s1 - s2 = difference

Constraints
1 <= arr[i]

Input
4
9 1
1 1 1 1 1 1 1 1 2
10 1
1 1 1 1 1 1 1 1 2 1
4 3
3 1 2 3
4 1
1 1 2 3

Output
0 210 3 3
*/


#include <iostream>
#include <vector>

using namespace std;


int solve(int arr[], int n, int sum, vector <vector <int>> &dp) {
	if (sum == 0) return 1;
	else if (n == 0) return 0;
	else if (dp[n][sum] != -1) return dp[n][sum];

	int ans1 = 0;
	if (sum >= arr[n - 1]) ans1 = solve(arr, n - 1, sum - arr[n - 1], dp);
	int ans2 =  solve(arr, n - 1, sum, dp);

	return dp[n][sum] = ans1 + ans2;
}

// Bottom Up
int targetDifference1(int arr[], int n, int difference) {
	int sum = 0, count = 0;
	for (int i = 0; i < n; ++i) sum += arr[i];

	int targetSum = (sum + difference) / 2;
	if ((2 * targetSum) - difference != sum) return 0;

	vector <vector <int>> dp(n + 1, vector <int> (targetSum + 1, -1));
	return solve(arr, n, targetSum, dp);
}


// Top Down
int targetDifference2(int arr[], int n, int difference) {
	int sum = 0, count = 0;
	for (int i = 0; i < n; ++i) sum += arr[i];

	int targetSum = (sum + difference) / 2;
	if ((2 * targetSum) - difference != sum) return 0;

	vector <vector <int>> dp(n + 1, vector <int> (targetSum + 1, -1));
	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < targetSum + 1; ++j) {
			if (j == 0) dp[i][j] = 1;
			else if (i == 0) dp[i][j] = 0;
			else {
				int ans1 = 0;
				if (j >= arr[i - 1]) ans1 = dp[i - 1][j - arr[i - 1]];
				int ans2 = dp[i - 1][j];

				dp[i][j] = ans1 + ans2;
			}
		}
	}

	return dp[n][targetSum];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, difference;
		cin >> n >> difference;
		int arr[n];
		for (int i = 0; i < n; ++i) cin >> arr[i];

		cout << targetDifference1(arr, n, difference) << " " << targetDifference2(arr, n, difference) << "\n";
	}

	return 0;
}
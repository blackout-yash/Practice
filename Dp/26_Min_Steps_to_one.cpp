// Min Steps to one
// Link - https://www.codingninjas.com/codestudio/problems/min-steps-to-one-using-dp_920548?leftPanelTab=0



#include <iostream>
#include <vector>

using namespace std;


int solve(int n, vector <int> &dp) {
	if (n == 1) return 0;
	else if (dp[n] != -1) return dp[n];

	int ans1, ans2, ans3;
	ans2 = ans3 = INT_MAX;

	ans1 = 1 + solve(n - 1, dp);
	if (n % 2 == 0) ans2 = 1 + solve(n / 2, dp);
	if (n % 3 == 0) ans3 = 1 + solve(n / 3, dp);

	return dp[n] = min(ans1, min(ans2, ans3));
}


// Top Down
int countStepsToOne1(int n) {
	vector <int> dp(n + 1, -1);
	return solve(n, dp);
}


// Bottom Up
int countStepsToOne2(int n) {
	int dp[n + 1] = {0};

	for (int i = 2; i < n + 1; i++) {
		int ans = dp[i - 1];
		if (i % 2 == 0) ans = min(ans, dp[i / 2]);
		if (i % 3 == 0) ans = min(ans, dp[i / 3]);
		dp[i] = ans + 1;
	}

	return dp[n];
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << countStepsToOne1(n) << " " << countStepsToOne2(n) << "\n";
	}

	return 0;
}
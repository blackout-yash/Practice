// B - Frog 2
// Link - https://atcoder.jp/contests/dp/tasks/dp_b



#include <bits/stdc++.h>
using namespace std;
#define ll int
#define fora(a,b) for(ll i=a;i<b;i++)


// Bottom Up
int minCost1(int h[], int n, int k, vector <int> &dp) {
	if (n == 0 || n == 1) return 0;
	if (dp[n] != -1) return dp[n];

	int minimum = INT_MAX;
	fora(1, k + 1) {
		if (n > i) minimum = min(minimum, abs(h[0] - h[i]) + minCost1(h + i, n - i, k, dp));
	}
	return dp[n] = minimum;
}


// Top Down
int minCost2(int h[], int n, int k) {
	int dp[n + 1];
	dp[0] = dp[1] = 0;

	for (int i = 2; i < n + 1; ++i) {
		int minimum = INT_MAX;
		for (int j = 1; j < k + 1; ++j) {
			if (i >= (j + 1)) {
				minimum = min(minimum, abs(h[i - 1] - h[i - 1 - j]) + dp[i - j]);
				dp[i] = minimum;
			}
		}
	}
	return dp[n];
}


int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	int h[n];
	fora(0, n) cin >> h[i];

	vector <int> dp(n + 1, -1);
	cout << minCost1(h, n, k, dp) << " " << minCost2(h, n, k);
	return 0;
}
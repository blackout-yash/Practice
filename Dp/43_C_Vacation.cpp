// C - Vacation
// Link - https://atcoder.jp/contests/dp/tasks/dp_c



#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;


int solve(vector <vector <int>> &points, int n, int a, int b, int c, unordered_map <string, int> &dp) {
	if (n == 0) return 0;

	string temp = to_string(n) + to_string(a) + to_string(b) + to_string(c);
	if (dp.find(temp) != dp.end()) return dp[temp];

	int ans1 = 0, ans2 = 0, ans3 = 0;

	if (!a) ans1 = points[n - 1][0] + solve(points, n - 1, 1, 0, 0, dp);
	if (!b) ans2 = points[n - 1][1] + solve(points, n - 1, 0, 1, 0, dp);
	if (!c) ans3 = points[n - 1][2] + solve(points, n - 1, 0, 0, 1, dp);

	return dp[temp] = max(ans1, max(ans2, ans3));
}


// Top Down
int maxPoints1(vector <vector <int>> points, int n) {
	unordered_map <string, int> dp;
	return solve(points, n, 0, 0, 0, dp);
}


// Bottom Up
int maxPoints2(vector <vector <int>> points, int n) {
	int dp[n][3];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == 0) dp[i][j] = points[i][j];
			else {
				dp[i][j] = points[i][j];
				if (j == 0) dp[i][j] += max(dp[i - 1][1], dp[i - 1][2]);
				else if (j == 1) dp[i][j] += max(dp[i - 1][0], dp[i - 1][2]);
				else dp[i][j] += max(dp[i - 1][0], dp[i - 1][1]);
			}
		}
	}

	int maximum = 0;
	for (int i = 0; i < 3; ++i) maximum = max(maximum, dp[n - 1][i]);

	return maximum;
}


int main() {
	int n;
	cin >> n;
	vector <vector <int>> points(n, vector <int> (3));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> points[i][j];
		}
	}

	cout << maxPoints1(points, n) << " " << maxPoints2(points, n);
	return 0;
}
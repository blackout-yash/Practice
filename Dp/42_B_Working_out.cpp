// B. Working out
// Link - https://codeforces.com/problemset/problem/429/B



#include <iostream>
#include <vector>
using namespace std;


int calculateMax(vector <vector <int>> &dp1, vector <vector <int>> &dp2, vector <vector <int>> &dp3, vector <vector <int>> &dp4) {
	int m = dp1.size(), n = dp1[0].size(), maximum = 0;

	for (int i = 1; i < m - 1; ++i) {
		for (int j = 1; j < n - 1; ++j) {
			int ans1 =  dp1[i - 1][j] + dp3[i][j - 1] + dp2[i][j + 1] + dp4[i + 1][j];
			int ans2 = dp1[i][j - 1] + dp2[i - 1][j] + dp3[i + 1][j] +  dp4[i][j + 1];
			maximum = max(maximum, max(ans1, ans2));
		}
	}
	return maximum;
}


// Bottom Up
int maxGain(vector <vector <int>> &calories, int m, int n) {
	vector <vector <int>> dp1(m, vector <int> (n)), dp2(m, vector <int> (n)), dp3(m, vector <int> (n)), dp4(m, vector <int> (n));

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == 0 && j == 0) dp1[i][j] = calories[i][j];
			else if (i == 0) dp1[i][j] = calories[i][j] + dp1[i][j - 1];
			else if (j == 0) dp1[i][j] = calories[i][j] + dp1[i - 1][j];
			else dp1[i][j] = calories[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = n - 1; j >= 0; --j) {
			if (i == 0 && j == n - 1) dp2[i][j] = calories[i][j];
			else if (i == 0) dp2[i][j] = calories[i][j] + dp2[i][j + 1];
			else if (j == n - 1) dp2[i][j] = calories[i][j] + dp2[i - 1][j];
			else dp2[i][j] = calories[i][j] + max(dp2[i - 1][j], dp2[i][j + 1]);
		}
	}

	for (int i = m - 1; i >= 0; --i) {
		for (int j = 0; j < n; ++j) {
			if (i == m - 1 && j == 0) dp3[i][j] = calories[i][j];
			else if (i == m - 1) dp3[i][j] = calories[i][j] + dp3[i][j - 1];
			else if (j == 0) dp3[i][j] = calories[i][j] + dp3[i + 1][j];
			else dp3[i][j] = calories[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);
		}
	}

	for (int i = m - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			if (i == m - 1 && j == n - 1) dp4[i][j] = calories[i][j];
			else if (i == m - 1) dp4[i][j] = calories[i][j] + dp4[i][j + 1];
			else if (j == n - 1) dp4[i][j] = calories[i][j] + dp4[i + 1][j];
			else dp4[i][j] = calories[i][j] + max(dp4[i + 1][j], dp4[i][j + 1]);
		}
	}

	return calculateMax(dp1, dp2, dp3, dp4);
}


int main() {
	int m, n;
	cin >> m >> n;

	vector <vector <int>> calories(m, vector <int> (n));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> calories[i][j];
		}
	}
	cout << maxGain(calories, m, n);
	return 0;
}
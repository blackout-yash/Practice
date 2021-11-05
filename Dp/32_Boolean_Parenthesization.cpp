// Boolean Parenthesization
// Link - https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#



#include <iostream>
#include <vector>
#include <unordered_map>
const int mod =  1003;
using namespace std;


int count(char c, int left_true, int left_false, int right_true, int right_false, bool flag) {
	int temp = left_true * right_true + left_true * right_false + left_false * right_true + left_false * right_false;
	if (c == '&') {
		int temp1 = left_true * right_true;
		if (flag) return temp1;
		return temp - temp1;
	} else if (c == '|') {
		int temp1 = left_true * right_true + left_true * right_false + left_false * right_true;
		if (flag) return temp1;
		return temp - temp1;
	}
	int temp1 = left_true * right_false + left_false * right_true;
	if (flag) return temp1;
	return temp - temp1;
}



int solve1(string &str, int i, int j, bool flag, vector <vector <vector <int>>> &dp) {
	if (i > j) return 0;
	else if (i == j) {
		if (flag) return str[i] == 'T';
		else return str[i] == 'F';
	} else {
		int k = 0;
		if (flag) k = 1;
		if (dp[i][j][k] != -1) return dp[i][j][k];
	}

	int ans = 0;
	for (int k = i + 1; k < j; k += 2) {

		int left_true = solve1(str, i, k - 1, true, dp);
		int left_false = solve1(str, i, k - 1, false, dp);
		int right_true = solve1(str, k + 1, j, true, dp);
		int right_false = solve1(str, k + 1, j, false, dp);

		ans += count(str[k], left_true, left_false, right_true, right_false, flag);
	}

	int k = 0;
	if (flag) k = 1;
	return dp[i][j][k] = ans % mod;
}


// Top Down
int countWays1(int N, string S) {
	vector <vector <vector <int>>> dp(N, vector <vector<int>> (N, vector <int> (2, -1)));
	return solve1(S, 0, N - 1, true, dp);
}



int solve2(string &str, int i, int j, bool flag, unordered_map <string, int> &dp) {
	if (i > j) return 0;
	else if (i == j) {
		if (flag) return str[i] == 'T';
		else return str[i] == 'F';
	}

	const string temp = to_string(i) + to_string(j) + to_string(flag);
	if (dp.find(temp) != dp.end()) return dp[temp];

	int ans = 0;
	for (int k = i + 1; k < j; k += 2) {

		int left_true = solve2(str, i, k - 1, true, dp);
		int left_false = solve2(str, i, k - 1, false, dp);
		int right_true = solve2(str, k + 1, j, true, dp);
		int right_false = solve2(str, k + 1, j, false, dp);

		ans += count(str[k], left_true, left_false, right_true, right_false, flag);
	}

	return dp[temp] = ans % 1003;
}


// Top Down
int countWays2(int N, string S) {
	unordered_map <string, int> dp;
	return solve2(S, 0, N - 1, true, dp);
}



// Bottom Up
int countWays3(int N, string S) {
	int dp[N][N][2];

	for (int i = N - 1; i >= 0; --i) {
		for (int j = 0; j < N; ++j) {
			if (i > j) dp[i][j][0] = dp[i][j][1] = 0;
			else if (i == j) {
				dp[i][j][0] = dp[i][j][1] = 0;
				if (S[i] == 'T') dp[i][j][1] = 1;
				else if (S[i] == 'F')dp[i][j][0] = 1;
			} else {
				int ans1 = 0, ans2 = 0;
				for (int k = j - 1; k >= i + 1; k -= 2) {

					int left_true = dp[i][k - 1][1];
					int left_false = dp[i][k - 1][0];
					int right_true = dp[k + 1][j][1];
					int right_false = dp[k + 1][j][0];

					ans1 += count(S[k], left_true, left_false, right_true, right_false, false);
					dp[i][j][0] = ans1 % mod;

					ans2 += count(S[k], left_true, left_false, right_true, right_false, true);
					dp[i][j][1] = ans2 % mod;
				}
			}
		}
	}

	return dp[0][N - 1][1];
}



int main() {
	int t;
	cin >> t;
	while (t--) {
		int n; string s;
		cin >> n >> s;

		cout << countWays1(n, s) << " " << countWays2(n, s) << " " << countWays3(n, s) << "\n";
	}

	return 0;
}
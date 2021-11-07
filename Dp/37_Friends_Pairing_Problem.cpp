// Friends Pairing Problem
// Link - https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#



#include <iostream>
#include <vector>
const int mod = 1e9 + 7;
using namespace std;



long long solve(int n, vector <long long> &dp) {
	if (n == 0 || n == 1 || n == 2) return n;
	else if (dp[n] != -1) return dp[n];

	long long ans = solve(n - 1, dp) + (n - 1) * solve(n - 2, dp);

	return dp[n] = ans % mod;
}


// Top Down
int countFriendsPairings1(int n) {
	vector <long long> dp(n + 1, -1);
	return solve(n, dp);
}



// Bottom Up
int countFriendsPairings2(int n) {
	long long dp[n + 1];

	for (int i = 0; i < n + 1; ++i) {
		if (i <= 2) dp[i] = i;
		else dp[i] = (dp[i - 1] + (i - 1) * dp[i - 2]) % mod;
	}
	return dp[n];
}



// Bottom Up
int countFriendsPairings3(int n) {
	if (n <= 2) return n;

	long long a = 1, b = 2, c;
	for (int i = 3; i < n + 1; ++i) {
		c = (b + (i - 1) * a) % mod;
		a = b;
		b = c;
	}
	return c;
}



int main() {
	int t;
	cin >> t;
	while (t--) {
		int n = 10000;

		cout << countFriendsPairings1(n) <<  " " << countFriendsPairings2(n) << " " << countFriendsPairings3(n) << "\n";
	}

	return 0;
}
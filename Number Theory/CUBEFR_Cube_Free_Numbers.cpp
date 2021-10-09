// CUBEFR - Cube Free Numbers
// Link - https://www.spoj.com/problems/CUBEFR/



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set <int> s;
	fora(i, 2, 101) {
		int temp = i * i * i, j = 1;
		while (temp <= 1000000) {
			s.insert(temp);
			temp /= j; j++;
			temp *= j;
		}
	} vector <int> v(s.begin(), s.end());

	int t, k = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		auto it = lower_bound(v.begin(), v.end(), n);
		int index = it - v.begin();

		cout << "Case " << k++ << ": ";
		if (v[index] == n) cout << "Not Cube Free\n";
		else cout << n - index << "\n";
	}
	return 0;
}
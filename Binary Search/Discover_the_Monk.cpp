// Discover the Monk
// Link - https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/discover-the-monk/



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

bool binarySearch(int arr[], int n, int key) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == key) return true;
		else if (arr[mid] < key) start = mid + 1;
		else end = mid - 1;
	}
	return false;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q, key;
	cin >> n >> q;
	int arr[n];
	fora(i, 0, n) cin >> arr[i];
	sort(arr, arr + n);
	while (q--) {
		cin >> key;
		if (binarySearch(arr, n, key)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
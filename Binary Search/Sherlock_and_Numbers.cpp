// Sherlock and Numbers
// Link - https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/sherlock-and-numbers/



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

int binarySolver(int n, int k, int p, int arr[]) {
    int start = 0, end = k - 1, key = p, prev = 0;
    while (true) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] > key) end = mid - 1;
            else start = mid + 1;
        }
        key += (end + 1 - prev);
        if (end + 1 == k || end + 1 - prev == 0) break;
        else {
            start = end + 1; end = k - 1;
            prev = start;
        }
    }
    return (n >= key) ? key :  -1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k, p;
        cin >> n >> k >> p;
        int arr[k];
        fora(i, 0, k) cin >> arr[i];
        sort(arr, arr + k);
        cout << binarySolver(n, k, p, arr) << "\n";
    }

    return 0;
}
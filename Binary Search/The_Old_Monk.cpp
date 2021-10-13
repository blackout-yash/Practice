// The Old Monk
// Link - https://www.hackerearth.com/problem/algorithm/the-old-monk/?source=list_view



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)


int binarySolver(int a[], int b[], int n) {
    int maximum = 0;
    fora(i, 0, n) {
        int start = 0, end = i, minimum = i, key = b[i];

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (a[mid] <= key) {
                minimum = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        maximum = max(maximum, i - minimum);
    }
    return maximum;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n];
        fora(i, 0, n) cin >> a[i];
        fora(i, 0, n) cin >> b[i];
        cout << binarySolver(a, b, n) << "\n";
    }

    return 0;
}
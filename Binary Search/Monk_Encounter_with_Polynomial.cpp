// Monk's Encounter with Polynomial
// Link - https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/monks-encounter-with-polynomial/



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

int binarySolver(int a, int b, int c) {
    if (0 >= c) return 0;

    int start = 1, end, minimum = INT_MAX;

    while (true) {
        if (a * start * start + b * start >= c) {
            end = start;
            start /= 2;
            break;
        }
        start *= 2;
    }

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (a * mid * mid + b * mid >= c) minimum = min(minimum, mid);

        if (a * mid * mid + b * mid < c) start = mid + 1;
        else end = mid - 1;
    }

    return minimum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c, k;
        cin >> a >> b >> c >> k;
        cout << binarySolver(a, b, k - c) << "\n";
    }

    return 0;
}
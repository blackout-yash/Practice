// NFACTOR - N-Factorful
// Link - https://www.spoj.com/problems/NFACTOR/



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <int> v(1e6 + 1, 0);
    for (int i = 2; i < 1e6 + 1; i++) {
        if (v[i] == 0) {
            for (int j = i; j < 1e6 + 1; j += i) v[j]++;
        }
    }

    vector <vector<int>> ans(11, vector<int>(1e6 + 1));
    for (int i = 0; i < 11; ++i) {
        int count = 0;
        for (int j = 0; j < 1e6 + 1; ++j) {
            if (v[j] == i) count++;
            ans[i][j] = count;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int a, b, n, count = 0;
        cin >> a >> b >> n;

        cout << ans[n][b] - ans[n][a - 1] << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector <int> a(n + 1);

    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int j = 2; j <= n; j++) {
        int aj = a[j];
        // i + j % aj == 0
        // j mod aj == -i
        int i = aj - (j % aj);
        for (; i < j; i += aj) {
            if (i + j == aj * a[i]) ans++;
        }
    }
    cout << ans << "\n";
}

signed main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
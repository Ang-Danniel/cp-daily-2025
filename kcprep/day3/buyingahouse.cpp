#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, m, k; cin >> n >> m >> k;
    int a[n + 1];
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int dist = (n + 1) * 10;
    for (int i = m - 1; i >= 1; i--) {
        if (a[i] == 0) continue;
        if (a[i] <= k) {
            dist = min(dist, m - i);
            break;
        }
    }
    for (int i = m + 1; i <= n; i++) {
        if (a[i] == 0) continue;
        if (a[i] <= k) {
            dist = min(dist, i - m);
            break;
        }
    }

    cout << dist * 10;

    return 0;
}
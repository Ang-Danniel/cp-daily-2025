#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    int w[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    int dpl[n + 1], dpr[n + 1];
    int dplr[n + 1];

    dpl[1] = min(1, w[1]);
    dpr[n] = min(1, w[n]);
    int maxx = -1;
    for (int i = 2; i <= n; i++) {
        dpl[i] = min(dpl[i - 1] + 1, w[i]);
    }

    for (int i = n - 1; i >= 1; i--) {
        dpr[i] = min(dpr[i + 1] + 1, w[i]);
        dplr[i] = min(dpl[i], dpr[i]);
        maxx = max(dplr[i], maxx);
    }
    dplr[n] = min(dpr[n], dpl[n]);

    maxx = max(dplr[n], maxx);
    cout << maxx;
}
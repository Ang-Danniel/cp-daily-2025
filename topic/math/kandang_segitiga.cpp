#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                // y2 - y1 / x2 - x1 = y3 - y2 / x3 - x2
                int m1 = y[j] - y[i];
                m1 *= x[k] - x[j];

                int m2 = y[k] - y[j];
                m2 *= x[j] - x[i];

                if (m1 != m2) cnt++;
            }
        }
    }
    cout << cnt;
}
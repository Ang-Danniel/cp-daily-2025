#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, k, q; cin >> n >> k >> q;
    int a[k + 1];
    bool kotak[n + 1];
    
    for (int i = 1; i <= n; i++) {
        kotak[i] = false;
    }

    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        kotak[a[i]] = true;
    }

    for (int i = 0; i < q; i++) {
        int l; cin >> l;

        if (a[l] == n) {
            continue;
        }

        if (!kotak[a[l] + 1]) {
            kotak[a[l]] = false;
            kotak[a[l] + 1] = true;
            a[l]++;
        }
    }

    for (int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
}
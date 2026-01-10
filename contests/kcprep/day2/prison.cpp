#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, m; cin >> n >> m; 
    int l, r; cin >> l >> r;

    int a, b;

    for (int i = 1; i < m; i++) {
        cin >> a >> b;
        l = max(a, l);
        r = min(b, r);
    }

    if (r - l < 0) cout << 0;
    else cout << r - l + 1;

    return 0;
}
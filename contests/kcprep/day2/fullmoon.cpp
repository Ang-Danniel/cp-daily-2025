#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, m, p; cin >> n >> m >> p;
    int cnt = 0;
    while (m <= n) {
        cnt++;
        m += p;
    }

    cout << cnt;
    return 0;
}
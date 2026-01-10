#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    int ans[n + 1];
    for (int i = 1; i <= n; i++) {
        int in; cin >> in;
        ans[in] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}   
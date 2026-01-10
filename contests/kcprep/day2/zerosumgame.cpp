#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int in; cin >> in;
        ans += in;
    }
    cout << -ans;
    return 0;
}
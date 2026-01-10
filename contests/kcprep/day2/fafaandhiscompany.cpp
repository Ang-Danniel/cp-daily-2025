#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if ((n - i) % i == 0) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
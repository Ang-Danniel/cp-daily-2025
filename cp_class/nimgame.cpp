#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    set <int> s;
    for (int i = 0; i < n; i++) {
        int in; cin >> in;
        s.insert(in);
    }

    if (*s.begin() != 1) {
        cout << "Alice\n";
        return;
    }

    int val = -1;
    bool alicewin = 1;
    for (auto e: s) {
        if (e == *s.begin()) {
            val = e;
            continue;
        } 
        // 1 => Alice
        // 1 2 => Bob
        // 1 1 => Bob
        // 1 1 1 1 => Bob
        alicewin = !alicewin;
        if (abs(val - e) != 1) {
            break;
        } else {
            val = e;
        }
    }
    if (alicewin) cout << "Alice\n";
    else cout << "Bob\n";
}

signed main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    bool is_2025 = 0;
    bool is_2026 = 0;
    
    int best = 1000;
    
    for (int i = 3; i < n; i++) {
        char a = s[i - 3];
        char b = s[i - 2];
        char c = s[i - 1];
        char d = s[i];

        if (a == '2' && b == '0' && c == '2' && d == '5') {
            is_2025 = 1;
        } else if (a == '2' && b == '0' && c == '2' && d == '6') {
            is_2026 = 1;
        }

        int temp = 0;
        if (a != '2') temp++;
        if (b != '0') temp++;
        if (c != '2') temp++;
        if (d != '6') temp++;
        best = min(best, temp);
    } 

    if (!is_2025) {
        best = 0;
    }

    if (is_2026) {
        best = 0;
    }
    
    cout << best << endl;
}

signed main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;

#define int long long 

signed main() {
    int n, a, b; cin >> n >> a >> b;

    string no = "NO\n";
    string yes = "YES\n";
    string biner = "0";
    while (n > 0) {
        biner += '0' + (n & 1);
        n /= 2;
    }
    biner += '0';
    // reverse(biner.begin(), biner.end());
    // cout << biner << endl;
    int lenBiner = biner.length();

    if (a == b) {
        for (int i = 0; i < lenBiner - 4; i++) {
            if (biner[i] == biner[i + 2] && biner[i + 1] == biner[i + 3] && biner[i] != biner[i + 1]) {
                cout << no;
                return 0;
            }
        }
        cout << yes;
    } else {
        cout << no;
    }
}
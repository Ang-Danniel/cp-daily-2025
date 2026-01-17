#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;

    int l, r;
    int mid = n / 2 + 1;
    l = 3;
    r = 2 * (mid + 1) - 1 - 2;
    // N = 7 -> 4 -> 7 / 2 + 1

    for (int i = 1; i <= n; i++) {
        // pada baris i, kita akan mengeluarkan spasi sebanyak
        // n - i kali
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        if (i == 1 || i == mid || i == n) {
            for (int j = 1; j <= i * 2 - 1; j++) {
                cout << "*";
            }  
        } else if (i < mid) {
            for (int j = 1; j <= i * 2 - 1; j++) {
                if (j == 1 || j == i * 2 - 1) cout << "*";
                else cout << " ";
            }  
        } else {
            for (int j = 1; j <= i * 2 - 1; j++) {
                if (j == 1 || j == i * 2 - 1 || j == l || j == r) cout << "*";
                else cout << " ";
            }  
            l += 2;
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector <int> a (n, 0);
    vector <int> b (n, 0);
    vector <int> c (n, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int degatas = 0;
    
    for (int i = 0; i < n; i++) {
        bool satis = 1;
        for (int j = 0; j < n; j++) {
            if (a[(i + j) % n] >= b[j]) {
                satis = 0;
                break;
            } 
        }

        if (satis) degatas++;
    }

    int degbawah = 0;
    
    for (int i = 0; i < n; i++) {
        bool satis = 1;
        for (int j = 0; j < n; j++) {
            if (b[(i + j) % n] >= c[j]) {
                satis = 0;
                break;
            } 
        }

        if (satis) degbawah++;
    }

    cout << n * degbawah * degatas << endl;
}

signed main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
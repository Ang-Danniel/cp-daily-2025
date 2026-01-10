    #include <bits/stdc++.h>
    using namespace std;

    signed main() {
        int n; cin >> n;
        int gcdAll;
        for (int i = 0; i < n; i++) {
            if (i == 0) cin >> gcdAll;
            else {
                int x; cin >> x;
                gcdAll = gcd(gcdAll, x);
            }
        }

        if (gcdAll == 1) {
            cout << 2 << endl;
            cout << 4 << " " << 2 << endl;
            cout << 4 << " " << 2 << endl;
        } else {
            cout << 1 << endl;
            cout << gcdAll <<  " " << 1 << endl;
        }
    }
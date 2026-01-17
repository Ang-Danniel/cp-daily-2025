#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n; 
    int ar[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }

    int q; cin >> q;

    int type, k, x;
    while(q--) {
        cin >> type;    
        if (type == 1) {
            cin >> k >> x;
            ar[k] = x;
        } else {
            cin >> k;
            cout << ar[k] << endl;
        }
    }

    return 0;
}
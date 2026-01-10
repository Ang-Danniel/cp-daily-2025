#include <bits/stdc++.h>
using namespace std;

signed main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n; 
        int fi, se; cin >> fi;
    
        int bestdist = 2e9;
        bool nsorted = 0;
        for (int i = 1; i < n; i++) {
            cin >> se;
    
            if (se - fi < 0) {
                nsorted = 1;
            }
            bestdist = min(bestdist, se - fi);
    
            fi = se;
        }
    
        int ans = 0;
        if (nsorted ) cout << ans;
        else {
            ans = (bestdist / 2) + 1;
            cout << ans;
        } 
        cout << endl;
    }

    return 0;
}
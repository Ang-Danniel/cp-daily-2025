#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    int v[101] = {0};
    
    for (int i = 1; i <= n; i++) {
        int in;
        cin >> in >> v[in];
    }

    int liter = 0;
    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        liter += v[i];
        
        if (v[i] > 0) ans = liter;

        if (liter == 0) continue;
        else liter--;
    }

    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

signed main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int cnt[1001] = {0};
        int ar[n + 1];

        int unq = 0;
        for (int i = 0; i < n; i++) {
            int in; cin >> in;
            cnt[in]++;
            if (cnt[in] == 1) unq++;
        }

        int ans = 0;
        for (int i = unq; true; i++) {
            if (cnt[i] > 0) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
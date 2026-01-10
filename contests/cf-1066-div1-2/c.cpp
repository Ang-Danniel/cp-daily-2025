#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, q; cin >> n >> k >> q;
    int a[n + 5];
    int isMin[n + 5];
    int isMex[n + 5];
    memset(isMin, 0, sizeof isMin);
    memset(isMex, 0, sizeof isMex);
    memset(a, -1, sizeof a);
    int c, l, r;

    vector <pair<int, int>> mexing;
    for (int i = 0; i < q; i++) {
        cin >> c >> l >> r;
        if (c == 1) {
            isMin[l]++;
            isMin[r + 1]--;
        } else {
            isMex[l]++;
            isMex[r + 1]--;
            mexing.push_back({l, r});
        }
    }
    
    sort(mexing.begin(), mexing.end());

    // cout << isMin[1] << " " << isMex[1] << endl;
    if (isMin[1] >= 1 && isMex[1] >= 1) a[1] = k + 1;
    if (isMin[1] >= 1 && isMex[1] == 0) a[1] = k;
    if (isMin[1] == 0 && isMex[1] == 0) a[1] = k;
    for (int i = 2; i <= n; i++) {
        isMin[i] += isMin[i - 1];
        isMex[i] += isMex[i - 1];
        if (isMin[i] >= 1 && isMex[i] >= 1) a[i] = k + 1;
        if (isMin[i] >= 1 && isMex[i] == 0) a[i] = k;
        if (isMin[i] == 0 && isMex[i] == 0) a[i] = k;
        // cout << isMin[i] << " " << isMex[i] << endl;
    }

    for (auto mexPair: mexing) {
        int cnt = 0;
        bool exist[105] = {0};
        for (int i = mexPair.first; i <= mexPair.second; i++) {
            if (isMin[i] >= 1) continue;
            if (a[i] != -1) {
                exist[a[i]] = 1;
                continue;
            }
        }
        for (int i = mexPair.first; i <= mexPair.second; i++) {
            if (isMin[i] >= 1) continue;
            if (a[i] != -1) continue;
            while (exist[cnt] && cnt < k) {
                cnt++;
            }
            if (cnt == k) break;
            a[i] = cnt;
            cnt++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) a[i] = k + 1;
        cout << a[i] << " ";
    }
    cout << endl;
}

signed main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    int cnt[26] = {0};
    bool ans = 1;
    for (int i = 0; i < n; i++) {
        int ascii = (s[i] - 'a');
        cnt[ascii]++;

        if (cnt[ascii] > k) ans = 0;
        
    }

    if (ans) cout << "YES";
    else cout << "NO";
}
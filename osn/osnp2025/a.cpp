#include <bits/stdc++.h>
using namespace std;

signed main() {
    string S; cin >> S;
    int m = S.length();

    vector <int> osnpref(m, 0);
    vector <int> psuf(m, 0);

    vector <int> o(m, 0);
    vector <int> s(m, 0);
    vector <int> n(m, 0);


    for (int i = 0; i < m; i++) {
        char c = S[i];
        if (i == 0) {
            osnpref[i] = 0;
            o[i] = 0;
            s[i] = 0;
            n[i] = 0;
        } else {
            osnpref[i] = osnpref[i - 1];
            o[i] = o[i-1];
            s[i] = s[i-1];
            n[i] = n[i-1];
        }

        if (c == 'O') {
            o[i]++;
            osnpref[i]++;
        } 
        if (c == 'S') {
            s[i]++;
            osnpref[i]++;
        }
        if (c == 'N') {
            n[i]++;
            osnpref[i]++;
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        char c = S[i];
        if (i == m - 1) psuf[i] = 0;
        else psuf[i] = psuf[i + 1];
        if (c == 'P') {
            psuf[i]++;
        } 
    }

    int ans = 0;

    for (int i = 1; i < m; i++) {
        if (psuf[i] == 0) continue;
        if ( min(o[i-1], min(s[i-1], n[i-1])) == 0 ) continue;
        ans = max(ans, psuf[i] + osnpref[i - 1]);
    }
    if (ans == 0) cout << -1;
    else cout << ans;
}
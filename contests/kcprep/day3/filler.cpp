#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    string s; cin >> s;

    bool streak = 0;
    string akhir = "";

    int idx = 0;
    while (idx < n) {
        if (idx + 2 > n) {
            if (streak) {
                akhir += "***";
                idx++;
            } else {
                akhir += s[idx];
                idx++;
            }
            continue;
        }

        if (!streak) {
            if (s[idx] == 'o' && s[idx + 1] == 'g' && s[idx + 2] == 'o') {
                streak = 1;
                idx += 2;
            } else {
                akhir += s[idx];
                idx++;
            }
        } else {
            if (s[idx] == 'o' && s[idx + 1] == 'g' && s[idx + 2] == 'o') {
                idx += 2;
            } else {
                streak = 0;
                akhir += "***";
                idx++;
            }
        }
    }
    cout << akhir;
}
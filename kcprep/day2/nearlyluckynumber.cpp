#include <bits/stdc++.h>
using namespace std;

signed main() {
    string s;
    cin >> s;

    int cnt = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '4' || s[i] == '7') {
            cnt++;
        }
    }

    s = to_string(cnt);

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '4' && s[i] != '7') {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    string s; 
    getline(cin, s);
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            cout << "HARD\n";
            return 0;
        }
    }
    cout << "EASY\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

signed main() {
    int a, b, c; cin >> a >> b >> c;
    if (a == 5 && a == b && c == 7) {
        cout << "YES";

    } else if (b == 5 && c == b && a == 7) {
        cout << "YES";

    } else if (a == 5 && a == c && b == 7) {
        cout << "YES";
    } else {
        cout << "NO\n";
    }
    return 0;
}
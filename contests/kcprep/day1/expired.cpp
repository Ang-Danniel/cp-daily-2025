#include <bits/stdc++.h>
using namespace std;

signed main() {
    int a, b, x;
    cin >> x >> a >> b;
    if (b > a) {
        if (b - a <= x) cout << "safe";
        else cout << "dangerous"; 
    } else {
        cout << "delicious";
    }
    return 0;
}
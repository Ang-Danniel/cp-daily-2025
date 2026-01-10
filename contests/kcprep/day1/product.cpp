#include <bits/stdc++.h>
using namespace std;

signed main() {
    int a, b; cin >> a >> b;
    int ans = a * b; 
    if (ans % 2 == 1) cout << "Odd";
    else cout << "Even";
    return 0;
}
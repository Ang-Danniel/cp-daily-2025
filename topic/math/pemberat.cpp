#include <bits/stdc++.h>
using namespace std;

signed main() {
    long long b, k; cin >> k >> b; 
    long long sel = b - k;

    long long twoBig = 1ll;
    while (twoBig <= sel) {
        twoBig *= 2ll;
    }

    while (sel > 0) {
        if (sel >= twoBig){
            cout << twoBig << "\n";
            sel -= twoBig;
        } else {
            twoBig /= 2ll;
        } 
    }
}
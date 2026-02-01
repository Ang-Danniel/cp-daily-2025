#include <bits/stdc++.h>
#define int long long
using namespace std;

int pow(int a, int b, int mod) {
    if (b == 0) return 1;

    int rec = pow(a, (b / 2), mod) % mod;
    int leftover = 1;
    if (b & 1) {
        leftover = a;
    }

    int ans = (rec * rec) % mod;
    ans = (ans * leftover) % mod;
    return ans;
}

signed main() {
    int n; cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        
        int ans = pow(a, b, 1e9 + 7);
        cout << ans << endl;
    }
    return 0;
}
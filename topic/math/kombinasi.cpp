#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

int memo[1001][1001];

int combin(int i, int j) {

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (j == 0ll) {
        memo[i][j] = 1ll;
        return 1ll;
    } 
    int a = 0, b = 0;
    if (i - 1 >= j) {
        b = combin(i - 1, j) % mod;
    } 
    a = combin(i - 1, j - 1) % mod; 
    memo[i][j] = (a + b) % mod;
    return (a + b) % mod;
}

signed main() {
    int n, a, b; cin >> n >> a >> b;
    int ans = 0;
    memset(memo, -1, sizeof memo);

    for (int i = a; i <= b; i++) {
        ans += combin(n, min(i, n - i));
        ans %= mod;
    }
    cout << ans;
}
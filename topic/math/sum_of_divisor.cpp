#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <iomanip>
#include <complex>
#include <numeric>
#include <climits>
#include <cassert>
#include <cstring>
#include <chrono>
#include <random>

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define fi first
#define se second
#define ub upper_bound
#define lb lower_bound
#define pii pair<int,int>
#define pll pair<ll,ll>
#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)
using namespace std;
const ll MOD = 1e9 + 7;
#define semoga_ac ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef complex<double> P;
#define X real()
#define Y imag()
typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(){
    ll n; cin >> n; 
    ll f = -1;
    for (ll i = 1; (i * i) <= n; i++) {
        if ((i * i) == n) f++;
        else if (n % i == 0) f+=2;
    }

    if (n % 2 == 0) {
        ll m = n / 2;
        ll ans1 = (n - 1ll) % MOD;
        ans1 *= (m - f); 
        ans1 %= MOD;
        ll ans2 = n % MOD;
        ans2 *= f;
        ans2 %= MOD;

        ans1 += ans2;
        ans1 %= MOD;
        ll ans3 = 0;
        ll ans4 = 0;
        if (m % 2 == 0) {
            ans3 = m / 2;
            ans3 %= MOD;
            ans4 = (n + 2) % MOD;
            ans4 %= MOD;
            ans4 += (m - 1) % MOD;
            ans3 *= ans4;
            ans3 %= MOD;
        } else {
            ans3 = m % MOD;
            ans4 = (m + 1) % MOD;
            ans4 += (((m - 1) / 2) % MOD);
            ans3 *= ans4;
            ans3 %= MOD;
        }
        ans1 += ans3;
        ans1 %= MOD;
        cout << ans1 << endl;
        return;
    }
    ll md = n / 2;
    ll mu = md + 1;
    ll ans1 = (((n - 1) % MOD) * ((md - f) % MOD)) % MOD;
    ll ans2 = ((n % MOD) * f) % MOD;
    ans1 += ans2;
    ans1 %= MOD;
    cout << ans1 << endl;
    ll ans3 = 0;
    ll ans4 = 0;
    if (mu % 2 == 0) {
        ans3 = mu / 2;
        ans3 %= MOD;
        ans4 = (((((2 * mu) % MOD)) % MOD) + ((mu - 1) % MOD)) % MOD;
        ans3 *= ans4;
        ans3 %= MOD;
    } else {
        ans3 = mu % MOD;
        ans4 = ((mu % MOD) + (((mu - 1) / 2) % MOD)) % MOD;
        ans3 *= ans4;
        ans3 %= MOD;
    }

    cout << ans3 << endl;
    ans1 += ans3;
    ans1 %= MOD;
    cout << ans1 << endl;
}
int main(){
semoga_ac;

int t = 1;
while(t--) solve();
}
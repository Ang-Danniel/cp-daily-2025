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

ll dp[1000001];

void solve(){
    ll n; cin >> n;
    ll x; cin >> x;

    vector <ll> c;
    ll inp;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        c.pb(inp);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            if(j == c[i]) dp[j] += 1;
            else if (j > c[i]) dp[j] += dp[j - c[i]];   
            dp[j] %= MOD;
        }
    }

    cout << dp[x];
}
int main(){
semoga_ac;

int t = 1;
while(t--) solve();
}
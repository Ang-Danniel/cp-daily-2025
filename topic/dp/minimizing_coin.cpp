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
    int dp[1000001];

    int n; cin >> n;
    int x; cin >> x;

    vector <int> c;
    int inp;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        c.pb(inp);
    }

    for(int i = 1; i <= x; i++) {
        dp[i] = INT32_MAX;
        for(int j: c){
            if (i == j) dp[i] = min(dp[i], 1);
            else if (i - j > 0 && dp[i - j] != INT32_MAX) dp[i] = min(dp[i], dp[i-j] + 1);
        }
    }

    if (dp[x] == INT32_MAX) cout << -1;
    else cout << dp[x];
}
int main(){
semoga_ac;

int t = 1;
while(t--) solve();
}
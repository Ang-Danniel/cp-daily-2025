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
    int n; cin >> n; 
    int ar[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    } 

    queue<int> lst[n + 1];
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        int now = ar[i];
        if (now == 1) {
            dp[i] = max(dp[i-1], 1 + dp[i-1]);
        } else if (lst[now].size() == now - 1) {
            int bef = lst[now].front() - 1; 
            dp[i] = max(dp[i-1], now + dp[bef]);
            lst[now].pop();
        }
        dp[i] = max(dp[i-1], dp[i]);
        lst[now].push(i);
        // cout << i << ") " << dp[i] << endl;
    }
    cout << dp[n] << endl;
}
int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
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
    int n, m; cin >> n >> m;
    int cnt[m + 1];
    vector<int> ar[n + 1];
    memset(cnt, 0, sizeof(cnt));
    int del = 0;
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        for (int j = 0; j < l; j++) {
            int x; cin >> x;
            ar[i].pb(x);
            cnt[x]++;
        }
    } 

    for (int i = 1; i <= m; i++) {
        if (cnt[i] == 0) {
            cout << "NO\n";
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        bool noig = 0;
        for (int j = 0; j < ar[i].size(); j++) {
            if (cnt[ar[i][j]] - 1 <= 0) {
                noig = 1;
                break;
            }
        }
        if (!noig) {
            del++;
        }
        if (del == 2) {
            break;
        }
    }

    if (del < 2) cout << "NO\n";
    else cout << "YES\n";
}
int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
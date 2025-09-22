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
    string s; cin >> s;
    int z = 0;
    int o = 0;
    vector <pii> vp;
    for (char c: s) {
        if (c == '0') {
            z++;
            if (o >= 1) {
                vp.pb({o, 1});
                o = 0;
            }
        }
        else {
            o++;
            if (z == 1) {
                cout << "NO\n";
                return;
            } else if (z > 1) {
                vp.pb({z, 0});
                z = 0;
            }
        }
    }
    if (o >= 1) {
        vp.pb({o, 1});
        o = 0;
    } else {
        if (z == 1) {
            cout << "NO\n";
            return;
        }
        vp.pb({z, 0});
        z = 0;
    }

    /*
    2 0
    2 1
    3 0
    1 1
    4 0
    */
    cout << "YES\n";
    int cnt = 0;
    for (auto p: vp) {
        // cout << p.fi << " " << p.se << endl;
        if (p.se == 0) {
            cnt += p.fi;
            for (int i = 0; i < p.fi; i++){
                cout << cnt - i << " ";
            }
        } else {
            for (int i = cnt + 1; i <= cnt + p.fi; i++) {
                cout << i << " ";
            }
            cnt += p.fi;
        }
    }
    cout << "\n";
}
int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
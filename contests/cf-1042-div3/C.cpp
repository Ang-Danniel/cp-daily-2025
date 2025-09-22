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
#include <unordered_map>

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
    ll n, k; cin >> n >> k;
    map <ll, ll> ada;
    for (ll i = 0; i < n; i++) {
        ll temp; cin >> temp;
        if(temp != 0) {
            ll hasil1 = temp % k;
            if (hasil1 == 0) {
                temp = 0;
            } else {
                ll hasil2 = abs(hasil1 - k);
                temp = min(hasil1, hasil2);
            }
        }
        ada[temp]++;
    }
    bool salah = false;
    for (ll i = 0; i < n; i++) {
        ll temp; cin >> temp;
        if(salah) continue;
        if(temp != 0) {
            ll hasil1 = temp % k;
            if (hasil1 == 0) {
                temp = 0;
            } else {
                ll hasil2 = abs(hasil1 - k);
                temp = min(hasil1, hasil2);
            }
        }

        if (ada[temp] > 0) {
            ada[temp]--;
        } else {
            salah = true;
        }
    }
    if(salah) cout << "NO" << endl;
    else cout << "YES" << endl;
}
int main(){
semoga_ac;

ll t; cin >> t;
while(t--) solve();
}
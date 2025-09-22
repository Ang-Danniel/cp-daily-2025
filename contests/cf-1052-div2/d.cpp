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
    ll l, r; cin >> l >> r;
    map<ll, ll> a;

    vector <ll> tw;
    ll temp = 1; 
    while (temp <= r) {
        if (temp >= l) {
            tw.pb(temp);
        }
        temp *= 2;
    }
    ll sum = 0;
    ll n = tw.size();
    for (ll i = n - 1; i >= 0; i--) {
        ll tr, tp; 
        tr = tw[i] - 1;
        tp = tw[i];
        auto it1 = a.find(tp);
        auto it2 = a.find(tr);
        while (tp <= r && tr >= l && it1 == a.end() && it2 == a.end()) {
            a[tp] = tr;
            a[tr] = tp;
            sum += 2ll * (tr + tp);
            tp++;
            tr--;
            it1 = a.find(tp);
            it2 = a.find(tr);
        } 
    }

    for (ll i = l; i <= r; i++) {
        auto it1 = a.find(i);
        if (it1 == a.end()) {
            sum += 2 * i;
            a[i] = i;
        }
    }
    cout << sum << endl;
    for (ll i = l; i <= r; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
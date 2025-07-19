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

ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}

void solve(){
    int n; cin >> n;
    ll p[n], s[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    if (n == 1) {
        if (p[0] == s[0]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (__gcd(p[0], s[1]) != s[0]) {
                cout << "NO" << endl;
                return;
            } 
            continue;
        }
        if (i == n - 1) {
            if (__gcd(p[n-2], s[n-1]) != p[n-1]) {
                cout << "NO" << endl;
                return;
            } 
            continue;
        }

        ll a = lcm(p[i], s[i]);
        if (__gcd(a, p[i-1]) != p[i]) {
            cout << "NO" << endl;
            return;
        }
        if (__gcd(a, s[i+1]) != s[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
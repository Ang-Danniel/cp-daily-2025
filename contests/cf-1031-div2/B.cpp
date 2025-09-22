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
    ll w, h, a, b;
    cin >> w >> h >> a >> b;

    ll x1, y1, x2, y2; 
    cin >> x1 >> y1 >> x2 >> y2;

    // 6 5 2 3
    // -1 -2 5 4

    if (x1 > x2) {
        x1 = x1 ^ x2;
        x2 = x1 ^ x2;
        x1 = x1 ^ x2;
    }
    bool ovp1 = x2 <= (x1 + a - 1);

    if (y1 > y2) {
        y1 = y1 ^ y2;
        y2 = y1 ^ y2;
        y1 = y1 ^ y2;
    }

    bool ovp2 = y2 <= (y1 + b - 1);
    // cout << ovp1 << ovp2 << endl; 
    if (ovp1 && ovp2) {
        cout << "Yes" << endl;
        return;
    } else if (ovp1 && ((y1 + b - y2) % b) != 0) {
        cout << "No" << endl;
        return;
    } else if (ovp2 && ((x1 + a - x2) % a) != 0) {
        cout << "No" << endl;
        return;
    } else if (!ovp1 && !ovp2 && ((y1 + b - y2) % b) != 0 && ((x1 + a - x2) % a) != 0) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;

}

int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
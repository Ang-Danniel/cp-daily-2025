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

const ll whoosh = 1e9;
ll interactor = 0;

void move(char dir) {
    cout << "? " << dir << " " << whoosh << endl;
    cout << flush;
    cin >> interactor;
}

void solve(){
    int n; cin >> n;
    vector<pll> coor(n);

    ll xy, yx;
    xy = -2ll * whoosh;
    yx = 2ll * whoosh;
    for (int i = 0; i < n; i++) {
        cin >> coor[i].fi >> coor[i].se;
        xy = max(xy, coor[i].fi + coor[i].se);
        yx = min(yx, coor[i].se - coor[i].fi);
    }
    ll tracka = 100;
    ll trackb = 99;

    ll ab = 0;
    ll amb = 0;
    ll temp = 0;

    // cout << tracka << " " << trackb << endl;
    move('U');
    trackb += whoosh;

    // cout << tracka << " " << trackb << endl;
    move('U');
    trackb += whoosh;

    // cout << tracka << " " << trackb << endl;
    move('R');
    tracka += whoosh;

    // cout << tracka << " " << trackb << endl;
    move('R');
    tracka += whoosh;

    temp = interactor;
    ab = temp - 4ll * whoosh + xy;
    // cout << temp << endl;
    // cout << ab << endl;
    // cout << xy << endl;

    // cout << tracka << " " << trackb << endl;
    move('D');
    trackb -= whoosh;

    // cout << tracka << " " << trackb << endl;
    move('D');
    trackb -= whoosh;

    // cout << tracka << " " << trackb << endl;
    move('D');
    trackb -= whoosh;

    // cout << tracka << " " << trackb << endl;
    move('D');
    trackb -= whoosh;

    temp = interactor;
    amb = temp - yx - (4ll * whoosh);
    
    // cout << temp << endl;
    // cout << amb << endl;
    // cout << yx << endl;

    ll x = amb + ab;
    x /= 2ll;
    ll y = ab - x;

    cout << "! " << x << " " << y << endl;
}
int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
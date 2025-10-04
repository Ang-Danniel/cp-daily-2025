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
    int n, x, y, a, b; cin >> n >> x >> y >> a >> b;
    int diff = max(abs(x - a), abs(y - b));
    int maxx = -1;
    if (x < a && y < b) {
        maxx = max(maxx, max(a, abs(b - y)));
        maxx = max(maxx, max(b, abs(a - x)));
        if (diff > 1) {
            maxx = max(maxx, max(a, b));
        } 
    } else if (x < a && y > b) {
        maxx = max(maxx, max(a, abs(b - y)));
        maxx = max(maxx, max(abs(n - b), abs(a - x)));
        if (diff > 1) {
            maxx = max(maxx, max(a, abs(n - b)));
        } 
    } else if (x > a && y < b) {
        maxx = max(maxx, max(abs(n - a), abs(b - y)));
        maxx = max(maxx, max(b, abs(a - x)));

        if (diff > 1) {
            maxx = max(maxx, max(abs(n - a), b));
        } 
    } else if (x > a && y > b) {
        maxx = max(maxx, max(abs(n - a), abs(b - y)));
        maxx = max(maxx, max(abs(n - b), abs(a - x)));
        if (diff > 1) {
            maxx = max(maxx, max(abs(n - a), abs(n - b)));
        } 
    } else if (x == a) {
        if (y < b) {
            maxx = y + abs(y - b);
        } else {
            maxx = (n - y) + abs(y - b);
        }
    } else if (y == b) {
        if (x < a) {
            maxx = x + abs(x - a);
        } else {
            maxx = n - x + abs(x - a);
        }
    }
    cout << maxx << endl;
}
int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
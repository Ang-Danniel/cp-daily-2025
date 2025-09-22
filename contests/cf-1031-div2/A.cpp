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
    int k, a, b, x, y; cin >> k >> a >> b >> x >> y;

    if (b > a) {
        b = a ^ b;
        a = a ^ b;
        b = a ^ b;

        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }

    // cout << a << " " << x << endl;
    // cout << b << " " << y << endl;


    int ans = 0;

    // x is the expensive to start
    // if the expensive one at the start decrease less -> Do it then the cheap if still possible
    if (x <= y) {
        if (k >= a) {
            int temp = k - a;
            ans = temp / x;
            ans++;
            k -= ans * x;
        }

        if (k >= b) {
            int temp = k - b; 
            ans += temp / y;
            ans++;
        }
    } else {
        // if the cheapest one at the start decrese less -> DO IT ALL ALONG
        if (k >= b) {
            int temp = k - b;
            ans += temp / y;
            ans++;
        }
    }

    cout << ans << endl;

}
int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
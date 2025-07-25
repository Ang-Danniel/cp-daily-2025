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
    ll a[n+1], b[n+1], c[n+1], d[n+1];
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    ll cost = 0;
    // Check if a is 0 and b > d
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && b[i] > d[i]) {
            cost += abs(b[i] - d[i]);
            b[i] = d[i];
        } 
        
        if (b[i] > d[i]) {
            ll temp = abs(b[i] - d[i]);
            cost += temp + min(a[i], c[i]);
            b[i] = d[i];
        }

        if (a[i] > c[i]) {
            cost += abs(a[i] - c[i]);
        }
    }

    cout << cost << endl;

}
int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
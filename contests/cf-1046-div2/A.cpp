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


// m m l m m l m m
// banyak m tidak boleh lebih dari 2/3 dari total point
// total 8, 6 to 2 
// 8 * 2 / 3 => 5 + 1 = 6  

// m m l m m
void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    c -= a;
    d -= b;

    int total = a + b;
    int allowed = total / 3;
    
    if(a > b) swap(a, b);
    if (a < allowed) {
        cout << "NO" << endl;
        return;
    }

    total = c + d;
    allowed = total / 3;

    if(c > d) swap(c, d);
    if (c < allowed) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
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

int main(){
    semoga_ac;
    int n, m; cin >> n >> m;
    ll a[m + 1];
    ll b[n + 1];
    ll total = 0;

    a[1] = 0;
    for (int i = 1; i <= n; i++) {
        cout << "? " << i << " " << 1 << endl << flush;
        cin >> b[i];
    }

    for (int j = 2; j <= m; j++) {
        cout << "? " << 1 << " " << j << endl << flush;
        cin >> a[j];
        a[j] ^= b[1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            total += b[i] ^ a[j];
        }  
    }

    cout << "! " << total << endl;
}
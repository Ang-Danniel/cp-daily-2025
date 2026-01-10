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
    int n; cin >> n;
    int total = 0;
    int suffix = 0;
    int prefix = 0;
    int ans[n + 1];
    cout << "? " << 1 << " " << n << endl << flush;
    cin >> total;

    for (int i = n - 1; i > 1; i--) {
        cout << "? " << 1 << " " << i << endl << flush;
        cin >> prefix;
        ans[i + 1] = total - prefix - suffix;
        suffix += ans[i + 1];
    }

    cout << "? " << 2 << " " << n << endl << flush;
    cin >> prefix;
    ans[1] = total - prefix;
    suffix += ans[1];
    ans[2] = total - suffix; 

    cout << "!";
    for (int i = 1; i <= n; i++) cout << " " << ans[i];
}
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

    int pref[n + 1];
    int suff[n + 1];
    bool ans[n + 1];
    memset(ans, true, sizeof(ans));
    pref[1] = 1;
    suff[n] = 1;
    for (int i = 2; i <= n; i++) {
        cout << "? " << 1 << " " << i << endl << flush;
        cin >> pref[i];
        if (pref[i] <= pref[i - 1]) ans[i] = false;
    }

    for (int i = n - 1; i >= 1; i--) {
        cout << "? " << i << " " << n << endl << flush;
        cin >> suff[i];
        if (suff[i] <= suff[i + 1]) ans[i] = false;
    }

    vector <int> loc;
    for (int i = 1; i <= n; i++) {
        if (ans[i]) loc.push_back(i);
    }
    cout << "! " << loc.size();
    for (auto i: loc) {
        cout << " " << i;
    }
}
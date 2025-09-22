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

struct loc {
    int x;
    int y;
};

void solve(){
    int n, m, k; cin >> n >> m >> k;
    string mc[n + 1];
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> mc[i];
    }

    int pref[n + 1][m + 1];
    memset(pref, 0, sizeof(pref));
    vector <loc> locs;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mc[i][j] == 'g') {
                total++;
                if (i == 0 && j == 0) pref[i][j] = 1;
                else if (i == 0) pref[i][j] = pref[i][j-1] + 1;
                else if (j == 0) pref[i][j] = pref[i-1][j] + 1;
                else pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + 1;
            } else {
                if (i == 0 && j == 0) pref[i][j] = 1;
                else if (i == 0) pref[i][j] = pref[i][j-1] + 1;
                else if (j == 0) pref[i][j] = pref[i-1][j] + 1;
                else pref[i][j] = pref[i-1][j] + pref[i][j-1]  - pref[i-1][j-1] + 1;
                
                pref[i][j]--;
            }

            if (mc[i][j] == '.') {
                loc temp;
                temp.x = i;
                temp.y = j;
                locs.pb(temp);
            }
            // cout << pref[i][j] << " ";
        }
        // cout << endl;
    }
    int minn = MOD;
    for (auto l: locs) {
        int tl = 0;
        if (l.x - k >= 0 &&  l.y - k >= 0) {
            tl = pref[l.x - k][l.y - k];
        }

        int tx, ty;
        tx = min(l.x + k - 1, n - 1);
        ty = min(l.y + k - 1, m - 1);
        int br = pref[tx][ty];

        int bl = 0;
        if (l.y - k >= 0) {
            bl = pref[min(l.x + k - 1, n-1)][l.y - k];
        }

        int tr = 0;
        if (l.x - k >= 0) {
            tr = pref[l.x - k][min(l.y + k - 1, m-1)];
        }
        // cout << br << " " << tr << " " << bl << " " << tl << endl;
        br = br - tr - bl + tl;
        minn = min(br, minn);
    }

    if (minn == MOD) {
        cout << 0 << endl;
    } else cout << total - minn << endl;


}
int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
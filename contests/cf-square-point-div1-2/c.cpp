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
    int n, q; cin >> n >> q;
    int ar[n + 1];
    int p1[n + 1];
    int p0[n + 1];
    p1[0] = 0;
    p1[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        p1[i] = p1[i-1];
        p0[i] = p0[i-1];
        if (ar[i] == 0) {
            p0[i]++; 
        } else {
            p1[i]++;
        }
    }

    int sr[n + 1];
    memset(sr, -1, sizeof(sr));
    int id = 1;
    for (int i = 1; i <= n; i++) {
        if (sr[i] != -1) {
            sr[i] = id;
            // cout << id << " ";
            continue;
        }  

        int j = i + 1;
        while (j <= n && ar[j - 1] != ar[j]) {
            sr[j] = 0;
            id = j;
            j++;
        }

        if (id < i) {
            id = i;
        }
        sr[i] = id;
        // cout << id << " ";
        if (id == i) {
            id++;
        }
    }
    // cout << endl;

    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        if ((r - l + 1) % 3 != 0) {
            cout << -1 << endl;
            continue;
        } 

        if ((p0[r] - p0[l - 1]) % 3 != 0) {
            cout << -1 << endl;
            continue;
        }

        if (sr[r] == sr[l]) {
            cout << (r - l + 1) / 3 + 1 << endl;
        } else {
            cout << (r - l + 1) / 3 << endl;
        }
    }
}
int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
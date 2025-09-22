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

    string grid[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    ll moves[n][n];
    memset(moves, 0, sizeof(moves));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                moves[i][j] = 0;
                continue;
            }
            
            if (i == 0 && j == 0) {
                moves[0][0] = 1; 
                continue;
            } 
            
            if (i == 0) {
                moves[i][j] = moves[i][j-1];
                continue;
            }
            
            if (j == 0) {
                moves[i][j] = moves[i-1][j];
                continue;
            }

            moves[i][j] = moves[i-1][j] + moves[i][j-1];
            moves[i][j] %= MOD;
        }
    }
    cout << moves[n-1][n-1];
}
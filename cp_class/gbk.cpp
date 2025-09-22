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
    string s1; cin >> s1;
    string s2; cin >> s2;

    int g1, b1, k1;
    g1 = b1 = k1 = 0;

    int g2, b2, k2;
    g2 = b2 = k2 = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] == 'G') g1++;
        if (s1[i] == 'B') b1++;
        if (s1[i] == 'K') k1++;
    }
    for (int i = 0; i < n; i++) {
        if (s2[i] == 'G') g2++;
        if (s2[i] == 'B') b2++;
        if (s2[i] == 'K') k2++;
    }

    cout << min(g1, k2) + min(b1, g2) + min(k1, b2);
}
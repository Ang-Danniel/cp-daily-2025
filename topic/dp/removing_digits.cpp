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

    int dp[n+1];
    dp[0] = 0;
    for(int i = 1; i <= min(n, 10); i++) {
        if(i < 10) dp[i] = 1;
        else if(i == 10) dp[i] = 2;
    }

    for(int i = 11; i <= n; i++) {
        dp[i] = INT_MAX - 1;
        int temp = i;
        while(temp > 0) {
            dp[i] = min(dp[i], dp[i - (temp % 10)] + 1);
            temp /= 10;
        }
    }

    cout << dp[n];

}
int main(){
semoga_ac;

int t = 1;
while(t--) solve();
}
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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    int streak = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            streak = 0; 
        } else {
            streak++;
        }

        if (streak >= k) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    int low = 1; 
    int high = n;
    for (int i = 0; i < n; i++){
        if (s[i] == '1') {
            cout << low << " ";
            low++;
        } else { 
            cout << high << " ";
            high--;
        }
    }
    cout << endl;
}
int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
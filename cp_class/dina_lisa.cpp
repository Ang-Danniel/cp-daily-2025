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

vector<bool> prime(100000, true);
vector<int> sieve(int n) {
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    vector<int> res;
    for (int p = 2; p <= n; p++){
        if (prime[p]){ 
            res.push_back(p);
        }
    }
    return res;
}

bool prime_check(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void solve(){   
    vector <int> listP = sieve(10000);
    prime[1] = false;
    int n; cin >> n;   
    if (n <= 100000) {
        if (prime[n]) {
            cout << 1 << endl;
            cout << n << endl;
            return;
        }        
    } 

    vector <int> ans;
    for (int i = n - 1; i >= 1; i--) {
        if (prime_check(i)) {
            n -= i;
            ans.pb(i);
            break;
        }
    }

    if (prime[n]) {
        cout << 2 << endl;
        cout << ans[0] << " " << n << endl;
        return;
    }

    for (int i = 0; true; i++) {
        if (prime[n - listP[i]]) {
            cout << 3 << endl;
            cout << ans[0] << " " << listP[i] << " " << n - listP[i] << endl;
            return;
        }
    }
}

int main(){
semoga_ac;
solve();
}
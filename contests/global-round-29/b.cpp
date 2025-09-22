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
    int ar[2 * (n + 1)];
    if (n == 1) {
        cout << "1 1" << endl;
        return;
    }
    if (n == 2) {
        cout << "2 1 2 1" << endl;
        return;
    }
    if (n % 2 == 1){
        int cnt = n;
        for (int i = 1; cnt > 1; i++){
            ar[i] = cnt;
            ar[i + cnt] = cnt;
            cnt-=2;
        }
        int fl = n / 2;
        ar[fl + 1] = 1;
        ar[2 * n] = 1;
        cnt = n - 1;
        ar[fl + 2] = cnt;
        ar[fl + 2 + cnt] = cnt;
        cnt -= 2;
        for (int i = n + 2; cnt > 1; i++){
            ar[i] = cnt;
            ar[i + cnt] = cnt;            
            cnt -= 2;
        }
    } else {
        int cnt = n;
        for (int i = 1; cnt > 1; i++){
            ar[i] = cnt;
            ar[i + cnt] = cnt;
            // cout << i << " " << cnt + i << endl;
            cnt-=2;
        }
        ar[2 * n] = 1;
        ar[(2 * n) - (n / 2) + 1] = 1;
        cnt = n - 1;

        ar[(n/2) + 1] = cnt;
        ar[(n/2) + 1 + cnt] = cnt;

        cnt -= 2;
        for (int i = n + 2; cnt > 1; i++){
            ar[i] = cnt;
            ar[i + cnt] = cnt;            
            cnt -= 2;
        }
    }
    for(int i = 1; i <= 2 * n; i++) {
        cout << ar[i] << " ";
    }
    cout << endl;
}
int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
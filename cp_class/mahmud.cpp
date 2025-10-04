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
    int x; cin >> x;

    if (n == 1) {
        cout << "YES" << endl;
        cout << x << endl;
        return;
    }

    if (n == 2) {
        if (x == 0) {
            cout << "NO" << endl;
            return;
        } else {
            cout << "YES" << endl;
            cout << 0 << " " << x << endl;
        }
        return;
    }

    int m = n / 4;
    int s = n % 4;

    if (s == 1) {
        cout << "YES" << endl;
        int cnt = 0;
        for (int i = 2; true; i+=4) {
            if (cnt == m) break;
            if (i <= x && x <= i + 3) continue;
            for (int j = i; j < i + 4; j++) {
                cout << j << " ";
            }
            cnt++;
        }
        cout << x << endl;
        return;
    }

    if (s == 2) {
        m--;
        cout << "YES" << endl;
        int cnt = 0;
        for (int i = 2; true; i+=4) {
            if (cnt == m) break;
            for (int j = i; j < i + 4; j++) {
                cout << j << " ";
            }
            cnt++;
        }
        if (x == 0) {
            cout << 262144 + 131072 << " " << 131072 << " " << 262144 << " " << 262144 + 131072 + 3 << " " << 131072 + 2 << " " << 262144 + 1 << endl;
        } else {
             cout << 262144 + 131072 << " " << 131072 << " " << 262144 + x << " " << 262144 + 131072 + 3 << " " << 131072 + 2 << " " << 262144 + 1 << endl;
        }
        return;
    }

    if (s == 3) {
        cout << "YES" << endl;
        int cnt = 0;
        for (int i = 2; true; i+=4) {
            if (cnt == m) break;
            for (int j = i; j < i + 4; j++) {
                cout << j << " ";
            }
            cnt++;
        }
        if (x == 0) {
            cout << 262144 + 131072 << " " << 131072 << " " << 262144 << endl;
        } else {
            cout << 131072 + x << " " << 131072 << " " << 0 << endl;
        }
        return;
    } 

    if (s == 0) {
        cout << "YES" << endl;
        m--;
        int cnt = 0;
        for (int i = 2; true; i+=4) {
            if (cnt == m) break;
            if (i <= x && x <= i + 3) continue;
            for (int j = i; j < i + 4; j++) {
                cout << j << " ";
            }
            cnt++;
        }
        cout << 262144 + 131072 << " " << 131072 << " " << 262144 << " " << x << endl;
        return;
    }

}
int main(){
semoga_ac;
solve();
}
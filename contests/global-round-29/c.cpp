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
    string s; cin >> s;
    
    if (s[0] == '0') {
        s = "110" + s; 
    } else {
        s = "1" + s;
    }

    n = s.length();
    if (s[n - 1] == '0') {
        s = s + "011";
    } else {
        s = s + "1";
    }
    n = s.length();

    vector <char> code;
    bool z = 0;
    int cnt = 0;
    // cout << s << endl;
    for(int i = 0; i < n; i++) {
        bool now = s[i] == '0';
        if (now == z) cnt++;
        else {
            if (z) {
                if (cnt > 1) code.pb('f');
                else code.pb('z');
            } else {
                if (cnt > 1) code.pb('b');
                else code.pb('t');
            }
            z = now;
            cnt = 1;
        }
    }
    if (z) {
        if (cnt > 1) code.pb('f');
        else code.pb('z');
    } else {
        if (cnt > 1) code.pb('b');
        else code.pb('t');
    }

    cnt = 1;
    n = code.size();
    bool streak = 0;
    cnt = 0;
    
    for (int i = 0; i < n; i++) {
        // cout << code[i] << endl;
        if (!streak) {
            if (code[i] == 'b') {
                streak = 1;
            } else {
                continue;
            }
            cnt = 0;
        } else {
            if (code[i] == 'z') {
                cnt++;
            } else if (code[i] == 't') {
                continue;
            } else if (code[i] == 'b') {
                if (cnt % 2 == 1) {
                    cout << "NO" << endl;
                    return;
                } else {
                    cnt = 0;
                }
            } else {
                streak = 0;
                cnt = 0;
            }
        }
    }
    cout << "YES" << endl;
}
int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
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

int cnt[30]; 
// index 0 -> A
// index 1 -> B

void solve(){
    string s; cin >> s;
    int odds = 0;

    for (int i = 0; i < s.length(); i++) {
        int char_int = (int) (s[i] - 'A');
        cnt[char_int]++;
    }  

    string front = "";
    string back = "";
    string mid = "";
    for (int i = 0; i <= 25; i++) {
        if (cnt[i] % 2 == 1) {
            odds++;
            for (int j = 0; j < cnt[i]; j++) {
                mid += ('A' + i);
            }
        } else {
            for (int j = 0; j < (cnt[i] / 2); j++) {
                char adds = ('A' + i);
                front += adds;
            }
        }
    }

    if (odds > 1) {
        cout << "NO SOLUTION" << endl;
        return;
    }  
    
    back = front;
    reverse(back.begin(), back.end());
    cout << front + mid + back;
}



int main(){
semoga_ac;

int t = 1;
while(t--) solve();
}
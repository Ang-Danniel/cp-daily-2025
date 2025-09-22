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
    ll n, p; cin >> n >> p;
    ll maxx, minn;
    maxx = minn = p;
    for (int i = 0; i < n; i++) {
        char op; cin >> op;
        ll input; cin >> input;
        ll tempMax1, tempMin1;
        if (op == '+') {
            tempMax1 = maxx + input;
            tempMin1 = minn + input;
        } else {
            tempMax1 = maxx * input;
            tempMin1 = minn * input;
        }
        
        cin >> op;
        cin >> input;
        ll tempMax2, tempMin2;
        if (op == '+') {
            tempMax2 = maxx + input;
            tempMin2 = minn + input;
        } else {
            tempMax2 = maxx * input;
            tempMin2 = minn * input;
        }

        maxx = max(tempMax1, tempMax2);
        maxx = max(maxx, tempMin2);
        maxx = max(tempMin1, maxx);

        minn = min(tempMax1, tempMax2);
        minn = min(tempMin1, minn);
        minn = min(minn, tempMin2);
    }
    cout << maxx << endl;
}
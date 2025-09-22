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
#include <unordered_map>

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
    vector <int> yal;
    unordered_map <int, int> cnt;
    int n; cin >> n;
    int ys;
    int ya;
    cin >> ys >> ys;
    cin >> ya >> ya;
    bool win = 0;
    if (ys < ya) {
        win = 1;
    }

    yal.pb(ys);
    cnt[ys] = 0;
    yal.pb(ya);
    cnt[ya] = 0;

    int yi;
    for (int i = 0; i < n; i++) {
        cin >> yi >> yi;
        if (cnt.find(yi) == cnt.end()) {
            cnt[yi] = -1;
            yal.push_back(yi);
        } else cnt[yi]--;
        cin >> yi >> yi;
        if (cnt.find(yi) == cnt.end()){
            yal.push_back(yi);
            cnt[yi] = 1;
        }
        else cnt[yi]++;
    }

    if (win) {
        cout << "0.0" << endl;
        return 0;
    }

    if (n == 0) {
        cout << ys - ya << ".0" << endl;
        return 0;
    }

    int sun = 0;
    int ex = 0;
    sort(yal.begin(), yal.end());

    for (int i = yal.size() - 1; i >= 0; i--) {
        int j = yal[i];
        ex += cnt[j];
        if (j <= ys && j >= ya) {
            if (ex <= 0) {
                if (i - 1 >= 0) {
                    sun += (j - max(ya, yal[i - 1]));
                } else {
                    sun += (j - ya);
                }
            }
        }
        // cout << ex << endl;
    }
    cout << sun << ".0" << endl;
}
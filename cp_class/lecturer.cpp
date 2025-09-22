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
    int n, k; cin >> n >> k;
    unordered_map < string, vector<int> > lect;
    for (int i = 0; i < n; i++) {
        int kred; cin >> kred;
        string name; cin >> name;

        auto it = lect.find(name);

        if (it == lect.end()) {
            lect.insert({name, {}});
        }
            
        lect[name].push_back(kred);
    }

    int cnt = 0;
    bool dpGen[k + 1];
    bool dpGan[k + 1];
    memset(dpGen, false, sizeof(dpGen));
    memset(dpGan, false, sizeof(dpGan));

    dpGen[0] = 1;
    dpGan[0] = 1;
    
    for (auto i: lect) {
        // cout << i.first << endl;
        if (cnt == 0) {
            for (int j: i.second) {
                dpGen[j] = 1;
                dpGan[j] = 1;
            }
            cnt++;
            continue;
        }

        if (cnt % 2 == 0){
            for (int j: i.second) {
                for (int l = k; l >= j; l--) {
                    if (dpGan[l - j]) dpGen[l] = 1;
                }

                for (int l = 0; l <= k; l++) {
                    dpGen[l] |= dpGan[l];

                    // if (cnt == 2) cout << dpGen[99] << endl;
                }
            }
        } else {
            for (int j: i.second) {
                for (int l = k; l >= j; l--) {
                    if (dpGen[l - j]) dpGan[l] = 1;
                }
                for (int l = 0; l <= k; l++) {
                    dpGan[l] |= dpGen[l];
                }
            }
        }

        cnt++;
    }

    // cout << dpGen[99] << endl;
    // cout << k << endl;

    for (int i = k; i >= 0; i--) {
        // cout << i << endl;
        if (dpGen[i] || dpGan[i]) {
            cout << i;
            return 0;
        }
    }

   
}
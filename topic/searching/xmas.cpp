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
    int n; cin >> n;
    ll x; cin >> x;

    ll ar[n + 1];
    vector<ll> prefBest;
    for(int i = 0; i <= n; i++) {
        cin >> ar[i]; 
    }
    
    sort(ar, ar + n);

    ll best1 = ar[n - 1];
    ll best2 = ar[n - 2];

    ll sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll twoTimes = 2ll * ar[i];
        if (twoTimes >= best1) {
            sum += twoTimes;
            prefBest.pb(sum);
        } else {
            for(int j = n - 1; j > i; j--) {
                sum += best1;
                prefBest.pb(sum);
            }
            for (int j = i; j >= 0; j--) {
                twoTimes = 2ll * ar[j];
                if (twoTimes >= best2) {
                    sum += twoTimes;
                    prefBest.pb(sum);
                    sum += best1;
                    prefBest.pb(sum);
                } else {
                    break;
                }
            }
            break;
        }

        if (i == 0) {
            for(int j = n - 1; j > i; j--) {
                sum += best1;
                prefBest.pb(sum);
            }
        }
    }

    ll m = prefBest.size();
    ll ans = 0;
    if (prefBest[m - 1] < x) {
        x -= prefBest[m - 1];
        ll sumBest = best1 + best2;
        ans = m + (x / sumBest) * 2ll;
        if (x % sumBest <= best2) {
            ans++;
        } else if (x % sumBest > best2) {
            ans+=2;
        }
    } else {
        int l, r, mid;
        l = 0;
        r = m - 1;
        while (l <= r) {
            mid = (l + r) / 2;
            if(prefBest[mid] >= x) {
                ans = mid + 1;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }

    // for(int i = 0; i < m; i++) cout << prefBest[i] << " ";
    // cout << endl;
    cout << ans << endl;
}   
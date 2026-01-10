#include <bits/stdc++.h>

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
#define popcnt __builtin_popcount
#define popcntll __builtin_popcount_ll
#define what(x) cout << #x << " = " << x << endl
using namespace std;
const ll MOD = 1e9 + 7;
const ll INFI = 1e9 + 7;
const ll INFL = 1e18 + 7;
const int NIL = 0;
#define cut_c ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto dist = uniform_int_distribution<int>(0, INFI);
auto distll = uniform_int_distribution<ll>(0, INFL);
int rnd() { return dist(rng); }
ll rndl() { return distll(rng); }
typedef complex<double> P;
#define X real()
#define Y imag()
typedef vector<int> vi;
typedef vector<vi> vvi;

void solve() {
    ll n, k; cin >> n >> k;
    vector <pair<ll, ll>> v(n + 1, {0, 0});
    for (ll i = 1; i <= n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin() + 1, v.end());
    if (n < k * 2) {
        cout << -1 << endl;
        return;
    }

    vector <pair<ll, ll>> ans;
    if (k == 0) {

        ll bossn = v[n].first;
        ll bossn2 = v[n - 1].first;

        ll idx = 1;
        for (ll i = 1; i <= n - 2; i++) {
            if (bossn - v[i].first > 0) {
                bossn -= v[i].first;
                ans.push_back({v[i].second, v[n].second});
                idx = i + 1;
            } else {
                break;
            }
        }

        if (bossn - bossn2 <= 0) {
            for (ll i = idx + 1; i <= n; i++) {
                ans.push_back({v[i].second, v[i - 1].second});
            }
            cout << ans.size() << "\n";
            for (auto p: ans) {
                cout << p.fi << " " << p.se << "\n";
            }
        } else {
            cout << -1 << endl;
        }
        return;
    }

    for (ll i = 2; i <= n - 2 * k + 1; i++) {
        ans.push_back({v[i - 1].second, v[i].second});
    }
    for (ll i = n - 2 * k + 2; i <= n; i+=2) {
        ans.push_back({v[i].second, v[i-1].second});
    }

    cout << ans.size() << "\n";
    for (auto p: ans) {
        cout << p.fi << " " << p.se << "\n";
    }
    return;
}

int main(){
cut_c;
   int t; cin >> t;
   while(t--){
    solve();
   }
}
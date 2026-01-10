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

using namespace std;
const ll MOD = 1e9 + 7;
#define semoga_ac ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef complex<double> P;
#define X real()
#define Y imag()
typedef vector<int> vi;
typedef vector<vi> vvi;

// Bila 1 spasi ke kanan/kiri butuh 1 spasi
// Bila 2 spasi ke kanan/kiri butuh 3 spasi (2 * i - 1)
// Tapi ada bonus bila sudah ke kiri dulu atau kanan dulu


void solve(){
    ll n, m, k; cin >> n >> m >> k;

    ll awalm = m;
    
    ll jarakmin = min(k - 1, n - k);
    ll jarakmax = max(k - 1, n - k);

    ll maxingbesar = ((awalm + 1) / 3) * 2 + 1;
    ll cover = maxingbesar / 2;
    cover = min(cover, jarakmin);
    maxingbesar = 2 * cover + 1;
    cout << maxingbesar << endl;
    m -= awalm - (((awalm % 3) + 1) % 3);
    maxingbesar += min(m, jarakmax - jarakmin);

    cout << cover << endl;
    cout << maxingbesar << endl;
    return;


}
int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
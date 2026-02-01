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
#define semoga_ac ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
typedef complex<double> P;
#define X real()
#define Y imag()
 
ll pow(ll a, ll b, ll mod){
    if(b == 0){
        return 1;
    }
    ll temp = pow(a,b/2, mod); 
    ll res = (temp*temp)%mod;
    if(b % 2){
        res = (res * a)%mod;
    }
    return res%mod;
}
 
main(){
semoga_ac;
    int n; cin >> n;
    ll a, b, c;
    ll mod = 1e9 + 7;
    while(n--){
        cin >> a >> b >> c;
        ll ans = pow(b, c, mod - 1);
        ans = pow(a, ans, mod);
        cout << ans << "\n";
    }
}
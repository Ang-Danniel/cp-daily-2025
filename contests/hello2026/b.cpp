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


void solve(){
    int n, k; cin >> n >> k;
    int cnt = -1;
    int stop = k - 2;

    // Jawaban adalah cnt + 1

    int ar[n + 1];
    for (int i = 0; i < n; i++) cin >> ar[i];
    sort(ar, ar + n);

    for (int i = 0; i < n; i++) {
        if (ar[i] == cnt + 1) {
            cnt++;
        }
    }

    cnt = min(cnt, stop);
    cout << cnt + 1 << endl;

}
int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
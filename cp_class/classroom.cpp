/*
Observasi:
- Bisa kita lihat bahwa ini adalah soal greedy klasik, yang terpenting disini adalah mendahulukan jadwal yang selesai lebih dulu. Alasan ini valid karena semakin cepat jadwal kelas selesai maka semakin banyak pula jadwal lain yang bisa masuk.
- Observasi lain yang dapat dilihat adalah bagaimana cara kita bisa meng assign jadwal ke kelas tertentu, kita ingin meng assign jadwal ke kelas yang mempunyai jadwal selesai terlama (selama valid). Ini dilakukan supaya masih terdapat kelas dengan jadwal selesai terkecil

Penyelesaian:
- Kita harus mencari struktur data yang cocok untuk melakukan operasi penambahan, update dan binary search seefisien mungkin, dan satu satunya yang memungkinkan adalah multiset karena rata rata operasi diatas membutuhkan o(log n) di multiset sehingga worst case kita hanya N Log N.
- Untuk mencari jadwal kelas yang waktu selesai nya paling lama, cukup di lowerbound saja
*/

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

bool comparator(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
    int n, k; cin >> n >> k;
    vector < pair<int, int> > sched;
    int x, y; 
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        sched.push_back(make_pair(x, y));
    }

    sort(sched.begin(), sched.end(), comparator);

    multiset<int> endd;
    
    int ans = 0;
    for (auto p : sched) {
        auto binser = endd.lower_bound(p.fi);
        if (binser == endd.begin() && endd.size() < k) {
            endd.insert(p.se);
            ans++;
        } else if (binser != endd.begin()){
            --binser;
            endd.erase(binser);
            endd.insert(p.se);   
            ans++;
        }
    }

    cout << ans;
}
int main(){
semoga_ac;
solve();
}
/*
Karena sudah dipastikan bahwa salah satu dari Bob atau Alice dijamin menghasilkan y maka kita hanya perlu menentukan siapakah yang tidak mungkin untuk membuat y.

Observasi: 
- Perhatikan 2 kemungkinan kasus berikut, dimana Alice bisa mendapatkan x ganjil dan Bob mendapatkan x genap atau sebaliknya karena Perbedaan dari kedua X adalah 3. 
- Bilangan genap + bil ganjil = bilangan ganjil 
- Bilangan ganjil + bil ganjil = bilangan genap
- Perhatikan bahwa a XOR b (mod 2) kongruen dengan a + b (mod 2), maka apapun pilihan yang Bob dan Alice dapatkan, hasil akhir tidak mungkin memenuhi persamaan d_alice (mod 2) kongruen dengan d_bob (mod 2) 
- Atau dalam kata lain d_alice (mod 2) tidak kongruen dengan d_bob (mod 2) sepanjang waktu.

Penyelesaian:
- Kita hanya perlu mengetahui hasil mod 2 akhir dari alice atau bob.
- Karena operasi dari XOR atau tambah tidak penting, kita cukup mengasumsikan operasi yang diambil adalah XOR dan melihat hasil mod 2 akhir dari d.
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

void solve(){
    ll n, x, y;
    cin >> n >> x >> y;
    ll hasil_xor = x;
    y %= 2;
    for (int i = 0; i < n; i++) {
        ll temp; cin >> temp;
        hasil_xor ^= temp;
    }

    hasil_xor %= 2;
    if (hasil_xor == y) { 
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
}
int main(){
semoga_ac;

int t; cin >> t;
while(t--) solve();
}
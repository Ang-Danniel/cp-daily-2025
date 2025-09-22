/*
Perhatikan bahwa pola berulang setelah n - 1 operasi

1 2 3 4 5 (1)
2 3 4 5 1 (2)
3 4 5 1 2 (3)
4 5 1 2 3 (4)
n - 1 kali

5 1 2 3 4 (5)
5 2 3 4 1 (6) 
5 3 4 1 2 (7)
5 4 1 2 3 (8)

5 1 2 3 4 (9)
5 2 3 4 1 (10)

Hal ini dapat terjadi karena elemen terdepan selalu elemen terbesar pada deque. Sehingga operasi berikutnya hanya memutar atau cycling array index 1 hingga n - 1

Kita cukup melakukan deque untuk 2(n - 1) operasi dan menyimpan hasilnya untuk dilakukan modulo untuk operasi yang lebih dari 2(n - 1).
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
#include <deque>

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
    ll q; cin >> q;
    deque<int> dq;

    int inp;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        dq.push_back(inp);
    }

    vector < pair<int, int> > first_list(n);

    for (int i = 1; i <= n - 1; i++) {
        int a = dq.front();
        dq.pop_front();
        int b = dq.front();
        dq.pop_front();

        first_list[i] = make_pair(a, b);
        
        if (a < b) swap(a, b);
        
        dq.push_front(a);
        dq.push_back(b);
    }

    int maxx = dq.front();

    vector <int> second_list(n);

    for (int i = 1; i <= n - 1; i++) {
        int a = dq.front();
        dq.pop_front();
        int b = dq.front();
        dq.pop_front();

        second_list[i] = b;
        
        if (a < b) swap(a, b);
        
        dq.push_front(a);
        dq.push_back(b);
    }

    while(q--) {
        ll ask; cin >> ask;
        if (ask <= n - 1) {
            cout << first_list[ask].first << " " << first_list[ask].second << endl;
        } else {
            ask %= (n - 1);
            if (ask == 0) ask = n - 1;
            cout << maxx << " " << second_list[ask] << endl;
        }
    }
}

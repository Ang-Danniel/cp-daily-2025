/*
- Kita mulai dari mencari bilangan terkecil dari input untuk mendefinisikan sebuah edges dalam sebuah tree. Bila pada suatu bilangan terkecil tertentu u ke v memiliki jalur (Cek dengan DSU) maka mereka bukanlah sebuah edges atau u dan v tidak terhubung dengan 1 edges. Dengan ini kita bisa mendapatkan struktur dari tree dan kemudian kita bisa melakukan pengecekkan dengan DFS.
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

int par[2001];
int ukuran[2001];
int outs[2001][2001];
vector < pair< int, pii > > e;
vector <pii> adj[2001];

bool dfs(int cur, int cum, int index, int bef) {
    if (outs[index][cur] != cum) return false;
    
    for (auto p: adj[cur]) {
        if (p.first == bef) continue;
        if (!dfs(p.first, cum + p.second, index, cur)) return false;
    }
    return true;
}

int find(int x) {
    if (x != par[x]) par[x] = find(par[x]);
    return par[x];
}

void union_sets(int a, int b) {
    int par_a = find(a);
    int par_b = find(b);
    if (par_a == par_b) return;
    if (ukuran[par_a] > ukuran[par_b]) swap(par_a, par_b);
    par[par_b] = par_a;
    ukuran[par_a] += ukuran[par_b];
}

int main(){
    semoga_ac;

    // setup parent
    for (int i = 1; i <= 2000; i++) {
        par[i] = i;
        ukuran[i] = 1;
    }

    int n; cin >> n;
    bool salah = 0;
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> outs[i][j];
            if (i == j) {
                if (outs[i][j] != 0) {
                    salah = 1;
                }
            } else {
                if (outs[i][j] == 0) {
                    salah = 1;
                }
                
                if (i > j && outs[i][j] != outs[j][i]) {
                    salah = 1;
                } 

                if (i < j) e.push_back(make_pair(outs[i][j], make_pair(i, j)));
            }
        }
    }

    if (salah) {
        cout << "NO" << endl;
        return 0;
    }

    sort(e.begin(), e.end());

    for (auto p: e) {
        int u = p.se.fi;
        int v = p.se.se;
        int nilai = p.fi;
        // cout << u << " " << v << " " << nilai << endl;

        if (find(u) != find(v)) {
            union_sets(u, v);
            adj[u].push_back(make_pair(v, nilai));
            adj[v].push_back(make_pair(u, nilai));
            // cout << u << " " << v << " " << nilai << endl;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!dfs(i, 0, i, 0)) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    
}
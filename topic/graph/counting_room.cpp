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
    int n, m; cin >> n >> m;
    string ar[n]; // index 0
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int ans = 0;
    bool vis[n][m];
    memset(vis, false, sizeof(vis));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(ar[i][j] == '#') continue;
            if(vis[i][j]) continue;
            
            queue < pair<int, int> > q;
            q.push(make_pair(i, j));
            vis[i][j] = true;
            // cout << "test " << i << " " << j << endl;
            while(!q.empty()) {
                pair<int, int> current = q.front();
                q.pop();

                // atas
                if (current.fi - 1 >= 0 && !vis[current.fi-1][current.se] && ar[current.fi-1][current.se] == '.') {
                    vis[current.fi-1][current.se] = true;
                    q.push(make_pair(current.fi-1, current.se));
                }
                // bawah
                if (current.fi + 1 < n && !vis[current.fi+1][current.se] && ar[current.fi+1][current.se] == '.') {
                    vis[current.fi+1][current.se] = true;
                    q.push(make_pair(current.fi+1, current.se));
                }
                // kiri kanan
                if (current.se - 1 >= 0 && !vis[current.fi][current.se-1] && ar[current.fi][current.se-1] == '.') {
                    vis[current.fi][current.se-1] = true;
                    q.push(make_pair(current.fi, current.se-1));
                }
                // kiri kanan
                if (current.se + 1 < m && !vis[current.fi][current.se+1] && ar[current.fi][current.se+1] == '.') {
                    vis[current.fi][current.se+1] = true;
                    q.push(make_pair(current.fi, current.se+1));
                }

            }

            ans++;
            // cout << i << " " << j << endl;
        }
    }
    cout << ans;
}
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
    vector<int> adj[n + 1];
    int parent[n + 1];
    bool vis[n + 1];
    memset(vis, false, sizeof(vis));


    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue <int> q; 
    q.push(1);
    vis[1] = true;

    parent[1] = -1;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for (int v: adj[current]) {
            if (!vis[v]) {
                vis[v] = true;
                parent[v] = current;
                q.push(v);
            }
        }
    }

    if (!vis[n]) {
        cout << "IMPOSSIBLE";
        return 0;
    } 

    vector <int> path;
    int node = n;
    while(parent[node] != -1) {
        path.push_back(node);
        node = parent[node];
    }
    // 5 4 1
    path.push_back(1);

    cout << path.size() << endl;
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }

}
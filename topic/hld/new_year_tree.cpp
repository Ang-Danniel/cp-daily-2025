#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = 1e9 + 7;

vector<int> parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
}

// SEG TREE

int n, t[800005];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] ^ t[v*2+1];
    }
}

int xors(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return xors(v*2, tl, tm, l, min(r, tm))
           ^ xors(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] ^ t[v*2+1];
    }
}

int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = xors(1, 0, n - 1, pos[head[b]], pos[b]);
        res = res ^ cur_heavy_path_max;
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = xors(1, 0, n - 1, pos[a], pos[b]);
    res = res ^ last_heavy_path_max;
    return res;
}

signed main() {
    cin >> n;
    vector<vector<int>> adj (n);
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ar[n];
    memset(ar, 0, sizeof ar);
    init(adj);
    build(ar, 1, 0, n - 1);

    int q; cin >> q;
    int t, u, x;
    for (int i = 0; i < q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> u >> x;
            u--;
            update(1, 0, n - 1, pos[u], x);
        } else {
            cin >> u;
            u--;
            // cout << "P" << xors(1, 0, n - 1, pos[3], pos[3]) << endl;
            // cout << "Q" << xors(1, 0, n - 1, pos[1], pos[1]) << endl;
            // cout << "R" << xors(1, 0, n - 1, pos[0], pos[0]) << endl;
            cout << query(0, u) << endl;
        }
        cout << "P" << xors(1, 0, n - 1, pos[3], pos[3]) << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

struct Aho {
    struct Node {
        int next[55];
        int link;
        int out;
        Node() {
            memset(next, -1, sizeof(next));
            link = -1;
            out = -1;
        }
    };

    vector<Node> t = {Node()};
    vector<bool> occ; 

    void insert(const string &s) {
        int v = 0;
        for (char c : s) {
            int x = c - 'a';
            if (x < 0) x = c - 'A' + 26;
            if (t[v].next[x] == -1) {
                t[v].next[x] = t.size();
                t.emplace_back();
            }
            v = t[v].next[x];
        }
        occ.push_back(0);
        t[v].out = occ.size() - 1;
    }

    void build() {
        queue<int> q;
        t[0].link = 0;
        for (int c = 0; c < 52; c++) {
            int u = t[0].next[c];
            if (u != -1) {
                t[u].link = 0;
                q.push(u);
            } else {
                t[0].next[c] = 0; 
            }
        }

        while (!q.empty()) {
            int v = q.front(); q.pop();
            int link = t[v].link;

            for (int c = 0; c < 52; c++) {
                int u = t[v].next[c];
                if (u != -1) {
                    t[u].link = t[link].next[c];
                    q.push(u);
                } else {
                    t[v].next[c] = t[link].next[c];
                }
            }
        }
    }

    void match(const string &s) {
        int v = 0;
        for (char c : s) {
            int x = c - 'a';
            if (x < 0) x = c - 'A' + 26;

            v = t[v].next[x];
            if(t[v].out != -1) {
                occ[t[v].out] = 1;
            }
        }
        return;
    }

    void bfs() {

    }
};

void solve() {
    string s; cin >> s;
    int n; cin >> n;
    Aho aho = Aho();
    for(int i = 0; i < n; i++) {
        string t; cin >> t;
        aho.insert(t);
    }

    aho.build();
    aho.match(s);

    for(auto u: aho.occ) {
        if (!u) cout << "n\n";
        if (u) cout << "y\n";
    }
}

signed main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
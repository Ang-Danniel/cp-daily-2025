#include <bits/stdc++.h>
using namespace std;

int v, e, k; 
int s, t; 

int heu[50005];
int cost[50005];
vector<pair <int, int>> adj[50005];


signed main() {
    cin >> v >> e >> k;    
    cin >> s >> t;

    int l, a, b, w; 
    for (int i = 0; i < e; i++) {
        
        cin >> l >> a >> b >> w;
        
        int u, v; 
        u = 5000 * l + a;
        v = 5000 * l + b;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    memset(heu, -1, sizeof heu);
    memset(cost, -1, sizeof cost);
    
    l = k - 1;
    int st = 5000 * l + s; 
    int tt = t;
    queue <int> q;
    q.push(st);
    heu[st] = 0;

    int fr, heufr;
    for (int i = l; i > 0; i--) {
        while(!q.empty()) {
            fr = q.front();
            heufr = heu[fr];
            q.pop();

            for (auto v: adj[fr]) {
                if (heu[v.first] == -1) {
                    heu[v.first] = heufr + 1;
                    heu[v.first - 5000] = heu[v.first];
                    q.push(v.first);
                } else if (heu[v.first] > heufr + 1) {
                    heu[v.first] = heufr + 1;
                    heu[v.first - 5000] = heu[v.first];
                    q.push(v.first);
                } 
            }
        }

        for (int j = 5000 * i; j <= 5000 * i + 4999; j++) {
            if (heu[j] != -1) {
                q.push(j - 5000);
                adj[j - 5000].push_back({j, 0});
            } 
        }
    }

    while(!q.empty()) {
        fr = q.front();
        heufr = heu[fr];
        q.pop();

        for (auto v: adj[fr]) {
            if (heu[v.first] == -1) {
                heu[v.first] = heufr + 1;
                q.push(v.first);
            } else if (heu[v.first] > heufr + 1) {
                heu[v.first] = heufr + 1;
                q.push(v.first);
            } 
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({-1, t});
    
    while(!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        if (cost[top.second] == -1) cost[top.second] = top.first;
        else {
            cost[top.second] = min(top.first, cost[top.second]);
        }
        
        if (top.second == st) {
            break;
        }

        for (auto v: adj[top.second]) {
            pq.push({top.first + v.second + heu[v.first], v.first});
            
        }
    }

    cout << cost[st];
}
#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 1005;
static const int INF  = 1e9;

static int A[MAXN][MAXN];
static int W[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, k;
    cin >> m >> n >> k;

    int N = max(n, m);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            W[i][j] = 0;
            A[i][j] = 0;
        }
    }

    for (int t = 0; t < k; t++) {
        int i, j, p;
        cin >> i >> j >> p;
        W[i][j] = p;
        A[i][j] = -p; 
    }

   vector<int> u (n+1), v (m+1), p (m+1), way (m+1);
    for (int i=1; i<=n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv (m+1, INF);
        vector<bool> used (m+1, false);
        do {
            used[j0] = true;
            int i0 = p[j0],  delta = INF,  j1;
            for (int j=1; j<=m; ++j)
                if (!used[j]) {
                    int cur = A[i0][j]-u[i0]-v[j];
                    if (cur < minv[j])
                        minv[j] = cur,  way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j],  j1 = j;
                }
            for (int j=0; j<=m; ++j)
                if (used[j])
                    u[p[j]] += delta,  v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    vector<int> ans (n+1, -1);
    for (int j=1; j<=m; ++j)
        ans[p[j]] = j;

    long long bestSum = v[0];
    cout << bestSum << "\n";

    vector <pair<int, int>> pairing;
    for (int i = 1; i <= n; ++i) {
        int j = ans[i];
        if (j != -1 && W[i][j] > 0) {
            pairing.push_back({i, j});
        }
    }

    cout << pairing.size() << "\n";

        
    for (pair<int, int> pairs: pairing) {
        cout << pairs.first << " " << pairs.second << "\n";
    }
}

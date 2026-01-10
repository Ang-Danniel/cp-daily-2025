#include <bits/stdc++.h>
using namespace std;

static const long long INF = (long long)4e18;

struct Hungarian {
    int n, m;
    vector<vector<long long>> a;
    vector<long long> u, v;
    vector<int> p, way;

    Hungarian(int n, int m) : n(n), m(m) {
        a.assign(n, vector<long long>(m, 0));
        u.assign(n + 1, 0);
        v.assign(m + 1, 0);
        p.assign(m + 1, 0);
        way.assign(m + 1, 0);
    }

    void add(int i, int j, long long cost) {
        a[i][j] = cost;
    }

    long long solve(vector<int>& assignment) {
        for (int i = 0; i < n; i++) {
            p[0] = i + 1;
            int j0 = 0;

            vector<long long> minv(m + 1, INF);
            vector<char> used(m + 1, false);

            do {
                used[j0] = true;
                int i0 = p[j0] - 1;
                long long delta = INF;
                int j1 = 0;

                for (int j = 1; j <= m; j++) {
                    if (used[j]) continue;
                    long long cur = a[i0][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }

                for (int j = 0; j <= m; j++) {
                    if (used[j]) {
                        u[p[j] - 1] += delta;
                        v[j] -= delta;
                    } else {
                        minv[j] -= delta;
                    }
                }

                j0 = j1;
            } while (p[j0] != 0);

            do {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0);
        }

        assignment.assign(n, -1);
        for (int j = 1; j <= m; j++)
            if (p[j] > 0)
                assignment[p[j] - 1] = j - 1;

        return -v[0]; 
    }
};
int main() {
    int n; cin >> n;
    Hungarian hungarian(n, n);

    long long a, b, k;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> k;

        for (long long j = 0; j < n; j++) {
            hungarian.add(i, j, -(max(a - min(k, j) * b, 0LL)));
        }
    }
    vector<int> match;
    long long cost = -hungarian.solve(match);

    cout << cost;
}
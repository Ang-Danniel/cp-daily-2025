#include <bits/stdc++.h>
using namespace std;

int idx = 1;
long long hungarian(vector<vector<long long>> cost) {
    int n = (int)cost.size();
    int m = (int)cost[0].size();
    const long long INF = (long long)4e18;

    vector<long long> u(n + 1), v(m + 1);
    vector<int> p(m + 1), way(m + 1);

    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        vector<long long> minv(m + 1, INF);
        vector<bool> used(m + 1, false);
        int j0 = 0;

        do {
            used[j0] = true;
            int i0 = p[j0], j1 = 0;
            long long delta = INF;

            for (int j = 1; j <= m; ++j) if (!used[j]) {
                long long cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                if (cur < minv[j]) {
                    minv[j] = cur;
                    way[j] = j0;
                }
                if (minv[j] < delta) {
                    delta = minv[j];
                    j1 = j;
                }
            }

            for (int j = 0; j <= m; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j]     -= delta;
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

    vector<int> assignment(n, -1);
    for (int j = 1; j <= m; ++j) {
        if (p[j] != 0) {
            assignment[p[j] - 1] = j - 1;
        }
    }

    long long min_cost = 0;
    for (int i = 0; i < n; ++i) {
        if (assignment[i] != -1)
            min_cost += cost[i][assignment[i]];
    }

    return min_cost;
}

void solve(int n) {
    vector <pair<long long, long long> >batu(n);
    vector <long long> r(n), c(n);
    for (long long i = 0; i < n; i++) {
        cin >> batu[i].first >> batu[i].second;
        r[i] = batu[i].first;
        c[i] = batu[i].second;
    }

    sort(r.begin(), r.end());
    sort(c.begin(), c.end());

    long long costV = 0;
    long long costH = 0;

    for (long long i = 0; i < n; i++) {
        costV += abs((i + 1) - c[i]);
        costH += abs((i + 1) - r[i]);
    }

    long long ans = (long long)4e18;
    for (long long i = 0; i < n; i++) {
        long long acc = 0;
        for (long long j = 0; j < n; j++) {
            acc += abs((i + 1) - r[j]);
        }
        ans = min(ans, acc + costV);
    }

    for (long long i = 0; i < n; i++) {
        long long acc = 0;
        for (long long j = 0; j < n; j++) {
            acc += abs((i + 1) - c[j]);
        }
        ans = min(ans, acc + costH);
    }

    vector<vector<long long>> cost(n);
    for (long long i = 0; i < n; i++) {
        for (long long j = 1; j <= n; j++) {
            cost[i].push_back(abs(j - batu[i].first) + abs(j - batu[i].second));
        }
    }
    
    ans = min(ans, hungarian(cost));

    for (long long i = 0; i < n; i++) {
        for (long long j = 1; j <= n; j++) {
            cost[i][j-1] = (abs(j - batu[i].first) + abs((n - j + 1) - batu[i].second));
        }
    }

    ans = min(ans, hungarian(cost));
    cout << "Board " << idx << ": " << ans  << " moves required." << endl << endl;
}

int main() {
    while (true) {
        int n; cin >> n;
        if (n == 0) return 0;
        solve(n);
        idx++;
    }
}

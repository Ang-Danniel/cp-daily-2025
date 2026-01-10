#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    int r; cin >> r;

    vector <int> x(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector <long double> y(n, 0.0);
    y[0] = r;
    for (int i = 1; i < n; i++) {
        y[i] = r;
        long double x0 = x[i];
        long double x1;
        
        for (int j = 0; j < i; j++) {
            x1 = x[j];
            long double sel = abs(x0 - x1);

            if (sel > 2 * r) continue;

            long double posy = y[j] + sqrtl(4.0 * r * r - sel * sel); 
            y[i] = max(y[i], posy);
        }
    }

    cout << fixed << setprecision(9);
    for (int i = 0; i < n; i++) {
        cout << y[i] << " ";
    }
}
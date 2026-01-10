#include <bits/stdc++.h>
using namespace std;

signed main() {
    int y; cin >> y;
    
    bool is4 = ((y % 4) == 0);
    bool is100 = ((y % 100) == 0);
    bool is400 = ((y % 400) == 0);

    if (!is4) {
        cout << 365; 
    } else {
        if (!is100) {
            cout << 366;
        } else {
            if (!is400) cout << 365;
            else cout << 366;
        }
    }

    return 0;
}
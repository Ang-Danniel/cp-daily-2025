#include <bits/stdc++.h>
using namespace std;

signed main() {
    int h, w, n; cin >> h >> w >> n;
    int hw[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> hw[i][j];
        }
    }

    int ans[] = {0, 0, 0};

    for (int k = 0; k < n; k++){
        int b; cin >> b;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (hw[i][j] == b) {
                    ans[i]++;                    
                }
            }
        }   
    }

    cout << max(ans[0], max(ans[1], ans[2]));
    return 0;
}
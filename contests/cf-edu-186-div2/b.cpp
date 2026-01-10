#include <bits/stdc++.h>
#define int long long
using namespace std;

int cnt2(int n) {
    int ans = 0;
    int tumpuk = 1;
    int awal = 2;
    while(n >= tumpuk) {
        tumpuk += awal;
        awal *= 2;
        ans++;
    }
    return ans;
}

void solve() {
    int s, b; cin >> s >> b;
    int k, best = -1;
    if (s > b) swap(s, b);

    // s -> b
    int tumpuk = 0;
    int awal = 1;
    if (s * 2 <= b) {
        k = cnt2(s + s * 2);
        for (int i = 0; i < k; i++) {
            tumpuk += awal;
            awal *= 2;
        } 
        
        if (s - (tumpuk / 3) >= awal) k++;
        best = max(best, k);
    } 

    tumpuk = 0;
    awal = 1;
    if (b / 2 <= s) {
        k = cnt2(b - (b % 2) + (b / 2));
        for (int i = 0; i < k; i++) {
            tumpuk += awal;
            awal *= 2;
        } 
        
        if (s - (tumpuk / 3) >= awal) k++;
        best = max(best, k);
    } 

    // b s
    tumpuk = 0;
    awal = 1;
    k = cnt2(s - (s % 2) + (s / 2));
    for (int i = 0; i < k; i++) {
        tumpuk += awal;
        awal *= 2;
    } 
    
    if (b - (tumpuk / 3) >= awal) k++;
    best = max(best, k);
    cout << best << endl;

}

signed main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
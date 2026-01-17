#include <bits/stdc++.h>
using namespace std;

signed main() {
    int a, b, c, d; cin >> a >> b >> c >> d;

    bool segment = 0;

    // TRIANGLE
    // a b c, d tidak kepakai
    // x + y > z => TRIANGLE (x <= y <= z)

    int z; // Nilai terbesar dari a, b, c
    int xy; // Nilai pertambahan 2 bilangan terkecil
    if (a > b) {
        if (a > c) {
            z = a;
        } else {
            z = c;
        }
    } else {
        if (b > c) {
            z = b;
        } else {
            z = c;
        }
    }
    // x + y
    xy = a + b + c - z;
    if (xy > z) {
        cout << "TRIANGLE";
        return 0;
    } else if (xy == z) {
        segment = true;
    }

    // a b d, c tidak kepakai
    if (a > b) {
        if (a > d) {
            z = a;
        } else {
            z = d;
        }
    } else {
        if (b > d) {
            z = b;
        } else {
            z = d;
        }
    }
    // x + y
    xy = a + b + d - z;
    if (xy > z) {
        cout << "TRIANGLE";
        return 0;
    } else if (xy == z) {
        segment = true;
    }

    // a c d, b tidak kepakai
    if (a > d) {
        if (a > c) {
            z = a;
        } else {
            z = c;
        }
    } else {
        if (d > c) {
            z = d;
        } else {
            z = c;
        }
    }
    // x + y
    xy = a + c + d - z;
    if (xy > z) {
        cout << "TRIANGLE";
        return 0;
    } else if (xy == z) {
        segment = true;
    }

    // b c d, a tidak kepakai
    if (b > d) {
        if (b > c) {
            z = b;
        } else {
            z = c;
        }
    } else {
        if (d > c) {
            z = d;
        } else {
            z = c;
        }
    }
    // x + y
    xy = b + c + d - z;
    if (xy > z) {
        cout << "TRIANGLE";
        return 0;
    } else if (xy == z) {
        segment = true;
    }

    if(segment == true) {
        cout << "SEGMENT";
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}
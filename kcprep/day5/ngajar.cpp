#include <bits/stdc++.h>
#include <vector>
using namespace std;

signed main() {
    vector <int> v; // {} <-
    cout << v.size();

    v.push_back(10);
    v.push_back(11);
    
    // v <- 10
    // v = {10}
    // v <- 11
    // v = {10, 11}

    vector <int> ar[5];
    ar[1].push_back(1);
    ar[1].push_back(2);
    ar[1].push_back(3);
    ar[1].push_back(4);
    ar[1].push_back(5);

    // ar[1] = {1, 2, 3, 4, 5}
    // ar[2] = {}
    // ar[3] = {}
    // ar[4] = {}

    // 1 5
    cout << ar[1][4];
}
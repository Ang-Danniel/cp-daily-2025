#include <iostream>
using namespace std;

int main() {
    int a; cin >> a;
    int x; cin >> x;
    
    string basestr = "";
    
    while (a > 0) {
        char new_digit = '0' + (a % x);
        basestr = new_digit + basestr;
        
        a /= x;
    }
    cout << basestr;
}
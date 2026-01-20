#include<iostream>
#define ll long long
using namespace std;
 
int main()
{
    int n; cin >> n;
    ll x0; cin >> x0;
    ll x;
    ll ans = 0;
    for(int i = 1; i < n; i++){
        cin >> x;
        if(x0 > x){
            ans += x0 - x;
        }else{
            x0 = x;
        }
    }
    cout << ans;
    return 0;
}

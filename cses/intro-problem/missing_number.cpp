#include<iostream>
using namespace std;
 
int main()
{
    long long n;
    int temp;
    cin >> n;
    temp = n-1;
    n = (n * (n+1))/2;
    for(int i = 0; i < temp; i++){
        int x; cin >> x;
        n -= x;
    }
    cout << n;
    
    return 0;
}

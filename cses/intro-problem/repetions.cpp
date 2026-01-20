#include<iostream>
using namespace std;
 
int main()
{
    string DNA;
    cin >> DNA;
    int n = DNA.length();
    int maxx = 1;
    int streak = 1;
    for(int i = 1; i < n; i++){
        if(DNA[i] == DNA[i-1]){
            streak++;
            maxx = max(streak, maxx);
        }else{
            streak = 1;
        }
    }
    cout << maxx;
    
    return 0;
}

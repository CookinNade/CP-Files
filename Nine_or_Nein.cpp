#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    // cin>>t;
    t = 1;
    while (t--){
        int n = 9;
        int a ,b;
        cin>>a>>b;
        if(a+b == n or a*b == n or a-b == n or (a/b == 9 and a%b == 0)){
            cout<<"Nine";
        }
        else cout<<"Nein";
    }
    return 0;
    }
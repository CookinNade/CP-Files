#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int a = n/2;
        int b = n/2;
        if(n%2)b++;
        cout<<a*b<<'\n';
    }
    return 0;
    }
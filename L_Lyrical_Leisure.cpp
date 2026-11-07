#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k; cin>>n>>k;
    for(int i=0;i<k;i++)cout<<'a';
    char c = 'b';
    
    for(int i=1;i<=n-k;i++,c++){
        if(c>122)c=97;
        cout<<c;
    }
    return 0;
    }
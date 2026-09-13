#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        // ll n;
        cin>>n;
        string s = to_string(n);
        ll dig = (int)s.size();
        ll y = 1;
        for(int i=0;i<dig;i++)y *=10;
        y++;
        cout<<y<<endl;
        
    }
    return 0;
    }
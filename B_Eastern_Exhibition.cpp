#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        vector<ll>x(n); vector<ll>y(n);
        for(int i=0;i<n;i++)cin>>x[i]>>y[i];
        sort(x.begin(),x.end()); sort(y.begin(),y.end());
        if((x.size())%2)a=1;
        else{
            c=x[x.size()/2];
            d=x[(x.size()/2)-1];
            a=c-d+1;
        }
        if((x.size())%2)b=1;
        else{
            c=y[x.size()/2];
            d=y[(x.size()/2)-1];
            b=c-d+1;
        }
        cout<<a*b<<endl;
        
    }
    return 0;
    }
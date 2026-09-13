#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    string s;
    pair<ll,ll>ranges[20];
    ll mex = 1e8+10;
    ranges[0]={0,0};
    ll num=0;
    ll mul =1;
    for(int i=1;i<18+1;i++){
        num= num+9*mul*(i);
        mul=mul*10;
        ranges[i].first=ranges[i-1].second+1;
        ranges[i].second=num;
    }
    ranges[18].second=mex;
    cin>>t;
    while (t--){
        cin>>n;
        ll dig;
        if(n<=9){
            cout<<n<<endl;
            continue;
        }
        for(int i=1;i<=18;i++){
            if(ranges[i].first<=n and n<=ranges[i].second){
                dig=i;break;
            }
        }
        n=n-ranges[dig].first;
        ll add= 1;
        ll rem = n%dig;
        ll lag = n/dig;
        for(int i=0;i<dig-1;i++){
            add=add*10;
        }
        add= add+lag;
        s = to_string(add);
        cout<<s[rem]<<endl;
    }
    return 0;
    }
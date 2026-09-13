#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,y; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>x>>y;
        map<pair<ll,ll>,vector<ll>>mp;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>a;
            arr[i]=a;
            b=a%x;
            c=a%y;
            // cout<<b<<" "<<c<<endl;
            mp[{b,c}].push_back(i);
        }
        // cout<<endl;
        ll ans =0;
        for(int i=0;i<n;i++){
            a=arr[i]%x;b=arr[i]%y;
            if(mp.find({x-a,b})!=mp.end()){
                auto &v = mp[{x-a,b}];
                auto it = upper_bound(v.begin(),v.end(),i);
                ans=ans+v.end()-it;
            }
            else if(a==0 and mp.find({0,b})!=mp.end()){
                auto &v = mp[{0,b}];
                auto it = upper_bound(v.begin(),v.end(),i);
                ans=ans+v.end()-it;
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
    }
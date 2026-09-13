#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n];
        map<ll,ll>mp;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++){
            a=arr[i];
            if(a%10==0)mp[a]++;
            else if(a%10==5)mp[a+5]++;
            else{
                while(a%10!=2){
                    // cout<<a<<" ";
                    a=a+(a%10);
                }
                mp[a%20]++;
            }
        }
        // for(auto it=mp.begin();it!=mp.end();++it){
        //     cout<<(*it).first<<" "<<(*it).second<<endl;
        // }
        // cout<<mp.size()<<endl;
        if(mp.size()==1)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
    }
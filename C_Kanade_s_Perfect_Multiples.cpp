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
    while (t--){
        cin>>n>>k;
        map<ll,ll>mp;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]]=0;
        }
        sort(arr,arr+n);
        int noer=0;
        vector<ll>v;
        for(int i=0;i<n;i++){
            a = arr[i];
            if(mp[a])continue;
            for(;a<=k;a=a+arr[i]){
                if(mp.find(a)==mp.end()){
                    noer++;
                    break;
                }
                else mp[a]=1;
            }
            if(noer)break;
            v.push_back(arr[i]);
        }
        
        if(noer)cout<<-1<<endl;
        else {
            cout<<v.size()<<endl;
            for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
            cout<<endl;
        }
        
    }
    return 0;
    }
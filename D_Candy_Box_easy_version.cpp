#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    while (t--){
        cin>>n;
        map<ll,ll>mp;
        for(int i=0;i<n;i++){
            cin>>a;
            mp[a]++;
        }
        set<ll>st;
        vector<ll>v;
        for(auto it = mp.begin();it!=mp.end();++it){
            v.push_back((*it).second);
        }
        sort(v.rbegin(),v.rend());
        ll ans=0,curr=v[0];
        // for(auto x:v)cout<<x<<" ";
        for(int i=0;i<v.size();i++){
            if(curr==0)break;
            if(st.find(v[i])==st.end()){
                st.insert(v[i]);
                ans=ans+v[i];
                curr=v[i]-1;
            }
            else{
                st.insert(curr);
                ans=ans+curr;
                curr--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
    }
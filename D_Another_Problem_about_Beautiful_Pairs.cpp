#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,x; 
    cin>>t;
    string s;
    while (t--){
        ll ans=0;
        cin>>n;
        map<ll,vector<ll>>mp;
        vector<ll>v;
        set<ll>st;
        for(int i=0;i<n;i++){
            cin>>a;
            st.insert(a);
            mp[a].push_back(i+1);
        }
        for(auto it=st.begin();it!=st.end();++it)v.push_back((*it));
        sort(v.begin(),v.end());
        m=v.size();
        cnt=0;
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<i;j++){
                a=v[i];b=v[j];
                if(a*b>n)break;
                ll nibo;
                ll bad;
                if(mp[a].size()>=mp[b].size()){
                    nibo=b;
                    bad=a;
                }
                else {
                    nibo =a;
                    bad=b;
                }
                for(int k=0;k<mp[nibo].size();k++){
                    ll beshi=a*b+mp[nibo][k];
                    auto it = lower_bound(mp[bad].begin(),mp[bad].end(),beshi);
                    if(it!= mp[bad].end() and (*it)==beshi){
                        ans++;
                        // cout<<beshi<<" "<<mp[nibo][k]<<endl;
                    }
                    beshi=mp[nibo][k]-a*b;
                    auto nit = lower_bound(mp[bad].begin(),mp[bad].end(),beshi);
                    if(nit!= mp[bad].end() and (*nit)==beshi){
                        ans++;
                        // cout<<beshi<<" "<<mp[nibo][k]<<endl;
                    }
                }
            }
        }
        for(int i=0;i<v.size();i++){
            a=v[i];
            if(a>n)break;
            for(int k=0;k<mp[a].size();k++){
                    ll beshi=a*a+mp[a][k];
                    auto it = lower_bound(mp[a].begin(),mp[a].end(),beshi);
                    if(it!= mp[a].end() and (*it)==beshi){
                        cnt++;
                        // cout<<beshi<<" c "<<mp[a][k]<<endl;
                        // cout<<"this is a d"<<a<<endl;
                    }
                    beshi=mp[a][k]-a*a;
                    auto nit = lower_bound(mp[a].begin(),mp[a].end(),beshi);
                    if(nit!= mp[a].end() and (*nit)==beshi){
                        cnt++;
                        // cout<<beshi<<"  c "<<mp[a][k]<<endl;
                        // cout<<"this is a d"<<a<<endl;
                        
                    }
                }
        }
        // cout<<ans<<endl;
        // cout<<cnt<<endl;
        cout<<ans+cnt/2<<endl;
    }
    return 0;
    }
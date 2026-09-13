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
        cin>>n>>m>>s;
        set<ll>st;
        set<ll>ans;
        ll arr[m];
        for(ll i=0; i<m;i++){
            cin>>arr[i];
            ans.insert(arr[i]);
            st.insert(arr[i]);
        }
        cnt=1;
        for(int i=0;i<n;i++){
            // cout<<cnt<<" ";
            if(s[i]=='A'){
                cnt++;
                ans.insert(cnt); st.insert(cnt);
                
            }
            else{
                auto it = st.upper_bound(cnt);
                ll val = *it;
                if(it!=st.end() and val-cnt>1 ){
                    cnt++;
                    st.insert(cnt); ans.insert(cnt);
                    auto nit = st.upper_bound(cnt);
                    ll val = *nit;
                    if(nit!=st.end() and val-cnt>1){
                        
                        cnt++;
                    }
                    else if(nit==st.end()){
                        cnt++;
                    }
                    else{
                        for(int j=val+1;;j++){
                            if(st.find(j)==st.end()){
                                cnt=j;
                                break;
                            }
                        }
                    }
                    // else{
                    //     cnt=val;
                    //     cnt++;
                    // }
                }
                else if(it==st.end()){
                        cnt++;
                        ans.insert(cnt);st.insert(cnt); 
                        cnt++;
                    }
                else{
                        for(int j=val+1;;j++){
                            if(st.find(j)==st.end()){
                                cnt=j;
                                ans.insert(cnt);st.insert(cnt); 
                                cnt++;
                                break;
                            }
                        }
                    }
            }
        }
        // cout<<endl;
        cout<<ans.size()<<endl;
        for(auto x:ans){
            cout<<x<<" ";
        }cout<<endl;
    }

    return 0;
    }
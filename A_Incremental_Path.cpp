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
        cin>>n>>m;
        cin>>s;
        set<ll>st;
        for(int i=0;i<m;i++){
            cin>>a;
            st.insert(a);
        }
        if(s[0]=='A')st.insert(2);
        else {
            for(ll i=2;i<=1e9+10;i++){
                if(st.find(i)==st.end()){
                    st.insert(i);
                    break;
                }
            }
        }
        ll start=1;
        for(ll i=1;i<n;i++){
            ll final=start;
            if(s[i-1]=='A')final++;
            else{
                final++;
                for(;;final++){
                    if(st.find(final)==st.end()){
                        break;
                    }
                }
            }
            start=final;
            if(s[i]=='A'){
                final++;
                st.insert(final);
                // cout<<final<<" "<<i+1<<endl;
            }
            else{
                final++;
                for(;;final++){
                    if(st.find(final)==st.end()){
                        st.insert(final);
                        // cout<<final<<" "<<i+1<<endl;
                        break;
                    }
                }
            }
        }
        cout<<st.size()<<endl;
        for(auto it =st.begin();it!=st.end();++it)cout<<(*it)<<" ";
        cout<<endl;
    }
    return 0;
    }
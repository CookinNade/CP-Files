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
        cin>>n>>k;
        set<ll>st;
        a=n;
        st.insert(1);st.insert(n);
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                // cout<<i<<" "<<n<<endl;
                st.insert(i);st.insert(n/i);
                // cout<<n<<endl;
            }
        }
        st.insert(n);
        // for(auto lit =  st.begin();lit!=st.end();++lit){
        //     cout<<*lit<<" ";
        // }cout<<endl;
        auto it=lower_bound(st.begin(),st.end(),k);
        if(it==st.end() or *it>k){
            --it;
            cout<<a/(*it)<<endl;
        }
        else cout<<a/(*it)<<endl;
    }
    return 0;
    }
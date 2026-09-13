#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    // cin>>t;
    t=1;
    string s;
    while (t--){
        cin>>n;
        set<ll>st;
        st.insert((n*(n+1))/2);
        st.insert(1);
        for(ll i=2;i*i<=n;i++){
            if(n%i==0){
                ll f=n/i;
                // cout<<f<<" "<<i<<endl;
                if(f%2){
                    ll avg=n+2;
                    st.insert(((f)/2)*avg + 1);
                }
                else{
                    ll avg = n+2-i;
                    st.insert(avg * (f/2));
                }
                swap(f,i);
                if(f%2){
                    ll avg=n+2;
                    st.insert(((f)/2)*avg + 1);
                }
                else{
                    ll avg = n+2-i;
                    st.insert(avg * (f/2));
                }
                swap(f,i);
            }
        }
        for(auto it = st.begin(); it!=st.end();++it){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    return 0;
    }
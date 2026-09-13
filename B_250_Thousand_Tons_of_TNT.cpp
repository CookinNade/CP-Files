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
        ll arr[n+1]={0};
        ll pajn[n+1]={0};
        ll sum=0;
        unordered_set<ll>bro; //// !!!!! Make it unordered later
        set<ll>st; //// !!!!! Make it ordered later
        for(int i=1;i<=n;i++){
            cin>>a;
            sum=sum+a;
            arr[i]=sum;
            pajn[i]=a;
        }
        bro.insert(1);
        if(n>2){
            for(int i=2;i*i<=n;i++){
                if(n%i==0){
                    bro.insert(n/i);
                    bro.insert(i);
                }
            }
        }
        m=-1;
        for(auto it=bro.begin();it!=bro.end();it++){
            st.clear();
            for(int j=1;j<=n/(*it);j++){
                if(j==1){
                    st.insert(arr[(*it)]);
                }
                else {
                    st.insert(arr[j*(*it)]-arr[(j-1)*(*it)]);
                }
            }
            auto lit = st.begin();
            auto mit =(--st.end());
            ll diff = (*mit)-(*lit);
            m = max(diff,m);
        }
        if(n==1){
            cout<<0<<endl;
        }
        else if(n==2){
            ll mx = max(pajn[1],pajn[2]);
            ll mn = min(pajn[1],pajn[2]);
            cout<<mx-mn<<endl;
        }
        else cout<<m<<endl;
        
    }
    return 0;
    }
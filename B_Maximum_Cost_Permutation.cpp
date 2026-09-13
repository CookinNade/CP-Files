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
        set<ll>st;
        int ind=-1;
        cnt=0;
        for(int i=0;i<n;i++){
            cin>>arr[i]; st.insert(arr[i]);
        }
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                cnt++; ind=i;
            }
        }
        l=n+2;
        r=-1;
        // cout<<ind<<endl;
        if(cnt==1 and st.find(ind+1)==st.end()){
            // cout<<"dhukse\n";
            for(ll i=0;i<n;i++){
                if(arr[i]!=i+1 and arr[i]!=0){
                    l=min(l,i); r=max(r,i);
                }
            }
        }
        else{
            for(ll i=0;i<n;i++){
                if(arr[i]!=i+1){
                    l=min(l,i); r=max(r,i);
                }
            }
        }
        if(r==-1)cout<<0<<endl;
        else cout<<r-l+1<<endl;

    }
    return 0;
    }
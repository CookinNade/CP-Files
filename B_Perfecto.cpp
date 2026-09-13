#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll N =5e5;
ll arr[500005];
int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n; 
    
    cin>>t;
    unordered_set<ll>st;
    
    for(ll i=1;i<=N;i++){
        st.insert(i*i);
    }
    ll sum=0;
    for(ll i=1;i<=N;i++){
        sum=sum+i;
        if(st.find(sum)!=st.end()){
            // cout<<"it gets here for i "<<i<<endl;
            arr[i]=i+1;arr[i+1]=i;i++;sum=sum+i;
        }
        else arr[i]=i;
    }
    while (t--){
        cin>>n;
        if(st.find(n*(n+1)/2)!=st.end()){
            cout<<-1<<endl;
        }
        else {
            for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
            cout<<endl;
        }
        
    }
    return 0;
    }
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e6+10;
ll hpf[N];ll spf[N]; 
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x;
    
    fill(hpf,hpf+N,0);
    fill(spf,spf+N,1e7);
    for(ll i=2;i<=N-5;i++){
        // cout<<"dhukse \n";
        if(hpf[i])continue;
        for(int j=i;j<N;j=j+i){
            hpf[j]=i;
            spf[j]=min(spf[j],i);
        }
    }
    hpf[1]=1; spf[1]=1;
    // for(int i=1;i<=10;i++)cout<<hpf[i]<<" "<<spf[i]<<endl;
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        bool yes = is_sorted(arr,arr+n);
        if(yes){
            cout<<"Bob\n";
            continue;
        }
        yes=true;
        for(int i=0;i<n;i++){
            if(i==n-1){
                if(spf[arr[i]]!=hpf[arr[i]])yes=false;
                break;
            }
            if(hpf[arr[i]]==spf[arr[i]] and hpf[arr[i]]<=spf[arr[i+1]])continue;
            else {
                yes=false;
                break;
            }
        }
        if(yes)cout<<"Bob\n";
        else cout<<"Alice\n";
    }
    return 0;
    }
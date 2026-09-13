#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k;
        ll ct[n+1];
        fill(ct,ct+n+1,0);
        ll a[n+1],b[n+1],ind[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ind[a[i]]=i;
        }
        
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=1;i<=n;i++){
            if(b[i]==-1)continue;
            ct[b[i]]++;
        }
        int no=0;
        for(ll i=1;i<=n;i++){
            c=b[i];
            if(c==-1)continue;
            if(ind[c]!=i){
                m=min(ind[c],i);
                m++;
                if(m+k-1<=n){
                    // cout<<"from here 1 #"<<c<<endl;;
                    no++;break;
                }
                m--;
                l=max(1,m-k+1);
                if(l+k-1<max(ind[c],i)){
                    no++;break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            // cout<<ct[i]<<" ";
            if(ct[i]>1){
                // cout<<"from here 3";
                
                no++;break;
            }
        }
        if(no)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
    }
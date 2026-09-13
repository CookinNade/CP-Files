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
        ll ctb[n+1];
        ll cta[n+1];
        fill(ctb,ctb+n+1,0);
        fill(cta,cta+n+1,0);
        pair<ll,vector<ll>>g[n+1];
        ll a[n+1],b[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
            g[a[i]].first=0;
            g[a[i]].second.push_back(i);
            cta[a[i]]++;
        }
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=1;i<=n;i++){
            if(b[i]==-1)continue;
            ctb[b[i]]++;
        }
        int no=0;
        
        for(ll i=1;i<=n;i++){
            c=b[i];
            if(c==-1)continue;
            bool ans=false;
            for(;g[c].first<g[c].second.size();g[c].first++){
                ll ind = g[c].second[g[c].first];

                if(ind==i)ans=true;
                if(ind!=i){
                    m=min(ind,i);
                    m++;
                    // cout<<"dhukse\n";
                    if(m+k-1<=n){
                        cout<<"from here 1 #"<<c<<" "<<i<<" "<<ind<<endl;
                        continue;
                    }
                    m--;
                    l=max(1,m-k+1);
                    if(l+k-1<max(ind,i)){
                        cout<<"from here 2 #"<<c<<" "<<i<<" "<<ind<<endl;
                        continue;
                    }
                    ans=true;
                }
                if(ans){
                    g[c].first++;
                    break;
                }
            }
            if(!ans){
                cout<<"from here 4 #"<<c<<endl;
                no++;break;
            }
        }
        for(int i=1;i<=n;i++){
            if(ctb[i]>cta[i]){
                cout<<"from here 3 #"<<endl;
                no++;
                break;
            }
        }
        if(no)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
    }
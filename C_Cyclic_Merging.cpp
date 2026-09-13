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
        vector<pair<ll,ll>>v;
        ll next[n];
        ll prev[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++){
            v.push_back({arr[i],i});
            a=i+1; if(a>=n)a=a-n;
            b=i-1; if(b<0)b=n+b;
            next[i]=arr[a];
            prev[i]=arr[b];
        }
        ll sum=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++){
            int ind = v[i].second;
            a=ind+1; if(a>=n)a=a-n;
            b=ind-1; if(b<0)b=n+b;

            // cout<<v[i].first<<" "<<prev[ind]<<" "<<next[ind]<<endl;
            // cout<<v[i].first<<" "<<prev[ind]<<" "<<next[ind]<<endl;
            if(i>=2){
                cout<<endl;
                for(int j=0;j<n;j++){
                    if(j==1 or j==2 or j==n-1){
                        cout<<prev[j]<<" "<<arr[j]<<" "<<next[j]<<endl;
                    }
                }
            }
            sum=sum+min(prev[ind],next[ind]);
            prev[a]=prev[ind];
            next[b]=next[ind];
        }
        
        cout<<sum<<endl;


        // for(int i=0;i<n;i++)cout<<next[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)cout<<prev[i]<<" ";
        // cout<<endl;
        
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i].first<<" "<<v[i].second<<" \n";
        // }cout<<endl;
    }
    return 0;
    }
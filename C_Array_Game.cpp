#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,zeroer; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k;
        vector<ll>v; ll srt[n];
        for(int i=0;i<n;i++) cin>>srt[i];
        sort(srt,srt+n);
        for(int i=1;i<n;i++) v.push_back(srt[i]-srt[i-1]);
        sort(v.begin(),v.end());
        zeroer=0;ll mn = min(v[0],srt[0]);ll fr,sr;
        if(k>2)cout<<0<<endl;
        else if(k==1) cout<<mn<<endl;
        else{
            
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    ll chk = srt[j]-srt[i];
                    auto it= lower_bound(srt,srt+n,chk);
                    if(it!=srt+n and *it==chk){
                        // cout<<srt[j]<<" "<<srt[i]<<endl;
                        zeroer++;break;
                    }
                    else if(it==srt+n){
                        --it;
                        fr = abs(*it-chk);
                        mn =min(mn,fr);
                    }
                    else if(it==srt){
                        fr = abs(*it-chk);
                        mn =min(mn,fr);
                    }
                    else{
                        fr = abs(*it-chk);
                        mn =min(mn,fr);
                        --it;
                        fr = abs(*it-chk);
                        mn =min(mn,fr);
                    }
                }
            }
            if(zeroer)cout<<0<<endl;
            else{
                cout<<mn<<endl; 
            }
        }
    }
    return 0;
    }
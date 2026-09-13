#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,l,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        vector<ll>vp;
        vector<ll>vn;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a>=0)vp.push_back(a);
            else vn.push_back(a);
        }
        sort(vp.rbegin(),vp.rend());
        sort(vn.begin(),vn.end());
        if(vp[0]==0){
            cout<<"No\n";
            continue;
        }
        // b = max(abs(vn[0]),vp[0]);
        k=0; int j=vn.size()-1;
        vector<ll>r;
        ll ans=0;
        a=0;
        for(int i=0;i<vp.size();i++){
            a=vp[i]+a;
            r.push_back(vp[i]);
            while(k<j and ans+abs(vn[k])<=a){
                ans=ans+abs(vn[k]);
                r.push_back(vn[k]);
                k++;
            }
            while(k<=j and ans+abs(vn[j])<=a){
                ans=ans+abs(vn[j]);
                r.push_back(vn[j]);
                j--;
            }
            // cout<<i<<" "<<a<<" "<<ans<<endl;

        }
        for(;k<=j;j--)r.push_back(vn[j]);
        cout<<"Yes\n";
        for(auto x:r)cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
    }
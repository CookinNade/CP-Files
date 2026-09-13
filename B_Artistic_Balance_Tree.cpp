#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>m;
        vector<ll>odd;
        vector<ll>even;
        for(int i=1;i<=n;i++){
            cin>>a;
            if(i%2)odd.push_back(a);
            else even.push_back(a);
        }
        sort(odd.rbegin(),odd.rend());
        sort(even.rbegin(),even.rend());
        // for(auto c:odd)cout<<c<<" ";
        // cout<<endl;
        // for(auto c:even)cout<<c<<" ";
        // cout<<endl;
        a=0;b=0;
        for(int i=0;i<m;i++){
            cin>>x;
            if(x%2){
                if(a==0)a++;
                else if(a>=(int)odd.size())continue;
                else if(odd[a]>0)a++;
                else continue;
            }
            else{
                if(b==0)b++;
                else if(b>=(int)even.size())continue;
                else if(even[b]>0)b++;
                else continue;
            }
        }
        ll ans=0;
        for(int i=a;i<odd.size();i++)ans=ans+odd[i];
        for(int i=b;i<even.size();i++)ans=ans+even[i];
        cout<<ans<<endl;
    }
    return 0;
    }
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        if(n<12){
            cout<<"NO\n";continue;
        }
        vector<ll>v;
        unordered_set<ll>st;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                v.push_back(i);st.insert(i);
                n=n/i;
                i=2;
            }
        }
        if(n>=2){ v.push_back(n);st.insert(n);}
        if(v.size()<3) cout<<"NO\n";
        else {
            sort(v.begin(),v.end());
            if(st.size()==1 and v.size()<6)cout<<"NO\n";
            else if(st.size()==2 and v.size()<4)cout<<"NO\n";
            else if(st.size()==1 and v.size()==6){
                a=v[0];
                cout<<"YES\n"<<a<<" "<<a*a<<" "<<a*a*a<<endl;
            }
            else{
                a=v[0]; ll ans=1;
                cout<<"YES\n"<<a<<" "<<v[v.size()-1]<<" ";
                for(int i=1;i<v.size()-1;i++) ans=ans*v[i];
                cout<<ans<<endl;
            }
            
        }
    }
    return 0;
    }
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
        k=n;
        vector<ll>v;
        while(k>0){
            for(int i=2;i<=500;i++){
                if((i*(i-1))/2 > k){
                    l=i;
                    break;
                }
            }
            // cout<<k<<endl;
            l--;
            k=k-((l*(l-1))/2);
            v.push_back(l);
            r--;
        }
        l=0; r=10000;
        cout<<accumulate(v.begin(),v.end(),0ll)<<endl;
        for(int i=0;i<v.size();++i){
            for(int j=0;j<v[i];j++){
                cout<<l<<" "<<r<<endl;
                r++;
            }
            l++; 
        }
    }
    return 0;
    }
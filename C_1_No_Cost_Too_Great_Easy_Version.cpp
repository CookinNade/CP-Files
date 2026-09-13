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
        map<ll,ll>mpo;
        map<ll,ll>mp1;
        for(int i=0;i<n;i++){
            cin>>a;
            b=a+1;
            for(ll j=2; j*j<=a;j++){
                if(a%j==0){
                    mpo[j]++;
                    a=a/j;
                    while(a%j==0) a=a/j;
                }
            }
            if(a!=1)mpo[a]++;
            
            for(ll j=2; j*j<=b;j++){
                if(b%j==0){
                    mp1[j]++;
                    b=b/j;
                    while(b%j==0) b=b/j;
                }
            }
            if(b!=1)mp1[b]++;
        }
        for(int i=0;i<n;i++){
            cin>>a;
        }
        int zero=0; int one =0;
        for(auto it=mpo.begin();it!=mpo.end();++it){
            if((*it).second>1){
                zero++; break;
            }
            ll itfirst=(*it).first;
            if((mp1.find(itfirst))!=mp1.end())one++;
        }
        if(zero)cout<<0<<endl;
        else if(one)cout<<1<<endl;
        else cout<<2<<endl;
        // for(auto it=mpo.begin();it!=mpo.end();++it){
        //     cout<<(*it).first<<" "<<(*it).second<<endl;
        // }cout<<"hello\n";
        // for(auto it=mp1.begin();it!=mp1.end();++it){
        //     cout<<(*it).first<<" "<<(*it).second<<endl;
        // }cout<<"hello\n";
    }
    return 0;
    }
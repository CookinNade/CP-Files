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
        pair<ll,ll> arr[n];
        ll arra[n];
        for(int i=0;i<n;i++){
            cin>>a;
            arra[i]=a;
            for(ll j=2; j*j<=a;j++){
                if(a%j==0){
                    mpo[j]++;
                    a=a/j;
                    while(a%j==0) a=a/j;
                }
            }
            if(a!=1)mpo[a]++;
            
            // for(ll j=2; j*j<=b;j++){
            //     if(b%j==0){
            //         mp1[j]++;
            //         b=b/j;
            //         while(b%j==0) b=b/j;
            //     }
            // }
            // if(b!=1)mp1[b]++;
        }
        for(int i=0;i<n;i++){
            cin>>a;
            arr[i]={a,i};
        }
        sort(arr,arr+n);
        ll ans=arr[0].first+arr[1].first;
        for(auto it=mpo.begin();it!=mpo.end();++it){
            if((*it).second>1){
                ans=0; break;
                // cout<<"hello\n";
            }
            // ll itfirst=(*it).first;
            // if((mp1.find(itfirst))!=mp1.end())one++;
        }
        int one=0;
        // cout<<ans<<endl;
        if(ans!=0){
            for(int i=0;i<n;i++){
                k=arr[i].second;
                a=arra[k];
                c=a;
                set<ll>fact;
                b=a+1;
                cout<<c<<" "<<ans<<endl;
                for(ll j=2;j*j<=a;j++){
                    // cout<<c<<"hello"<<endl;
                    if(a%j==0){
                        fact.insert(j);
                        auto nit = mpo.lower_bound(j);
                        if(nit!=mpo.end() and (*nit).second>1){
                            if((*nit).first==a){
                                if((*nit).second>1){
                                    ll diff=(*nit).first-j;
                                    ans=min(ans,diff*arr[i].first);
                                }
                            }
                            else{
                                auto bit = mpo.upper_bound(j);
                                if(bit!=mpo.end()){
                                    ll diff=(*nit).first-j;
                                    ans=min(ans,diff*arr[i].first);
                                }
                            }
                        }
                        a=a/j;
                        while(a%j==0) a=a/j;
                    }
                }
                
                if(a!=1){
                    if(mpo.find(a)!=mpo.end()){
                        auto nit = mpo.lower_bound(a);
                        cout<<(*nit).first<<" this"<<endl;
                        if(nit!=mpo.end() and (*nit).second>1){
                            if((*nit).first==a){
                                if((*nit).second>1){
                                    ll diff=(*nit).first-a;
                                    ans=min(ans,diff*arr[i].first);
                                }
                            }
                            else{
                                auto bit = mpo.upper_bound(a);
                                if(bit!=mpo.end()){
                                    ll diff=(*nit).first-a;
                                    ans=min(ans,diff*arr[i].first);
                                }
                                
                            }
                            
                        }
                    }
                }
                
                // cout<<"ans  mid way "<<ans<<endl;
                a=b;
                for(ll j=2;j*j<=a;j++){
                    if(a%j==0){
                        if(mpo.find(j)!=mpo.end()){
                            ans=min(ans,arr[i].first);
                        }
                        auto nit = mpo.lower_bound(j);
                        if(nit!=mpo.end()){
                            if((fact.find(j)!= fact.end() and (*nit).second>1) or fact.find(j)==fact.end()){
                                ll diff= (*nit).first-j+1;
                                ans=min(ans,diff*arr[i].first);
                            }
                        }
                        a=a/j;
                        while(a%j==0) a=a/j;
                    }
                }
                if(a!=1){
                    if(mpo.find(a)!=mpo.end()){
                        ans=min(ans,arr[i].first);
                        auto nit = mpo.lower_bound(a);
                        if(nit!=mpo.end()){
                            if((fact.find(a)!= fact.end() and (*nit).second>1) or fact.find(a)==fact.end()){
                                ll diff=(*nit).first-a+1;
                                ans=min(ans,diff*arr[i].first);
                            }  
                        }
                    }
                }
                cout<<ans<<" after first loop "<<c<<endl; 
            }
            
            
        }
        cout<<ans<<endl;
        // for(auto it=mpo.begin();it!=mpo.end();++it){
        //     cout<<(*it).first<<" "<<(*it).second<<endl;
        // }cout<<"hello\n";
        // for(auto it=mp1.begin();it!=mp1.end();++it){
        //     cout<<(*it).first<<" "<<(*it).second<<endl;
        // }cout<<"hello\n";
    }
    return 0;
    }
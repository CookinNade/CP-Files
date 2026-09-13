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
        cin>>n>>k;
        ll ar[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        // sort(ar,ar+n);
        cnt=0;
        vector<ll>v;
        for(int i=0;i<n;i++){
            if(ar[i]==0){
                v.push_back(1);
                continue;
            }
            for(int j=1; ar[i] >= (1LL<<(j-1)); j++){
                if(j==1){
                    if((((ar[i]>>0)&1)==1)){
                        cnt++;
                    }
                    else {
                        v.push_back(1);
                        // cout<<"it reacher here from bkabasdf\n"<<" current value of j "<<j;
                    }
                }
                if( (((ar[i]>>j)&1)==1) ){
                    cnt++;
                }
                else {
                    v.push_back(j+1);
                    // cout<<"it reacher here\n";
                }
            }
        }
        sort(v.begin(),v.end());
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<"\n ended here \n ";
        for(int i=0;i<v.size();i++){
            if(k-v[i]>=0){
                k=k-v[i];
                cnt++;
            }
            else break;
        }
        cout<<cnt<<endl;
    }
    return 0;
    }
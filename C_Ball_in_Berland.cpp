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
        cin>>a>>b>>k;
        ll freqb[a+1];
        ll freqg[b+1];
        ll arrb[k];
        ll arrg[k];
        fill(freqb+1,freqb+a+1,0ll);
        fill(freqg+1,freqg+b+1,0ll);
        for(int i=0;i<k;i++){
            cin>>arrb[i];
            freqb[arrb[i]]++;
        }
        for(int i=0;i<k;i++){
            cin>>arrg[i];
            freqg[arrg[i]]++;
        }
        // for(int i=1;i<=a;i++){
        //     cout<<freqb[i]<<" ";
        // }cout<<endl;
        // for(int i=1;i<=b;i++){
        //     cout<<freqg[i]<<" ";
        // }cout<<endl;
        ll sum=0;
        for(int i=0;i<k;i++){
            sum=sum+k-freqb[arrb[i]]-freqg[arrg[i]]+1;
        }
        cout<<sum/2<<endl;

    }
    return 0;
    }
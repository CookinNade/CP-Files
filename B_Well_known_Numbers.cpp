#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    // cin>>t;
    // while (t--){
        ll s,sum;
        vector<ll>v;
        cin>>s>>k;
        int N=1e5;
        ll arr[N];
        arr[0]=1;arr[1]=1;arr[2]=2;
        for(int i=3;;i++){
            if(i>=k){
                sum=0;
                for(int j=i-k;j<i;j++){
                    sum=sum+arr[j];
                    if(j==i-1){
                        arr[i]=sum;
                        break;
                    }
                }
            }
            else{
                sum=accumulate(arr,arr+i,0ll);
                arr[i]=sum;
            }
            // cout<<sum<<" ";
            if(sum>=s){
                cnt=i;
                break;
            }
            
        }
        sum=0;
        for(int i=cnt;sum!=s;i--){
            if(arr[i]>s-sum){
                continue;
            }
            else {
                sum=sum+arr[i];
                v.push_back(arr[i]);
            }
        }
        if(v.size()==1){
            cout<<2<<endl;
            cout<<0<<" "<<v[0]<<endl;
        }
        else {
            cout<<v.size()<<endl;
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    // }
    return 0;
    }
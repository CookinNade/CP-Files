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
        ll real[n+1]; ll freq[n+1]; ll arr[n];
        fill(freq,freq+n+1,0);
        fill(real,real+n+1,0);
        for(int i=0;i<n;i++){
            cin>>a;
            arr[i]=a;
            freq[a]++;
        }
        int noer=0;
        if(n%k)noer++;
        for(int i=1;i<=n;i++){
            if(freq[i]%k){
                noer++;
                break;
            }
            freq[i]=freq[i]/k;
        }
        if(noer){
            cout<<0<<endl;
            continue;
        }
        d=n/k;
        l=0;r=0;
        cnt=0;
        real[arr[0]]++;
        for(;r<n;){
            // real[arr[r]]++;
            cnt += r-l+1;
            // cout<<l<<" "<<r<<" "<<cnt<<endl;
            if(r==2){
                // cout<<real[x]<<" hellp "<<freq[x]<<endl;
            }
            r++;
            if(r==n)break;
            x=arr[r];
            real[x]++;
            
            if(real[x]>freq[x]){
                for(;;l++){
                    real[arr[l]]--;
                    if(arr[l]==x or l+1==r)break;
                }
                l++;
            }
            
            if(r-l+1>d){
                real[l]--;
                l++;
            }
            
        }
        cout<<cnt<<endl;
        // for(int i=1;i<=n;i++)cout<<freq[i]<<" ";
        // cout<<endl;
    }
    return 0;
    }
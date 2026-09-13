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
        x=0;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        if(arr[0]>=0){
            ll mn=LLONG_MAX;
            if(arr[n-1]<0){
                for(int j=n-1;j>=0;j--){
                    if(arr[j]>=0){
                        mn=min(arr[j],mn);
                        break;
                    }
                    else mn=min(mn,abs(arr[j]));
                }
                for(int i=0;i<n;i++)x=x+abs(arr[i]);
                x=x-mn;
            }
            else{
                for(int i=0;i<n-1;i++)x=x+abs(arr[i]);
            }
        }
        else{
            ll mn=1e15;
            ll cnt1 = arr[0];
            ll real[n];
            real[n-1]=arr[n-1];
            for(int i=n-2;i>=1;i--){
                real[i]=arr[i]+real[i+1];
            }
            if(arr[n-1]<0){
                ll suff[n];
                for(int j=n-1;j>=0;j--){
                    if(arr[j]>=0){
                        mn=min(arr[j],mn);
                        break;
                    }
                    else mn=min(mn,abs(arr[j]));
                }
                suff[n-1]=abs(arr[n-1]);
                for(int i=n-2;i>=1;i--){
                    suff[i]=abs(arr[i])+suff[i+1];
                }
                // cout<<"this is mn "<<mn<<endl;
                // for(int i=1;i<n;i++){
                //     cout<<real[i]<<" ";
                // }cout<<endl;
                // for(int i=1;i<n;i++)cout<<suff[i]<<" ";
                // cout<<endl;
                ll reall=LLONG_MIN;
                for(int i=1;i<n;i++){
                    if(arr[i]<0)x=x+abs(arr[i]);
                    else{
                        // cout<<cnt1+suff[i]-mn<<" "<<real[i]<<endl;
                        reall=max(cnt1+suff[i]-mn+x,reall);
                        reall=max(reall,real[i]-mn+x);
                        if(cnt1+suff[i]-mn >= real[i]){
                            x=x+cnt1+suff[i]-mn;
                            break;
                        }
                        else{
                            x=x-arr[i];
                            continue;
                        }
                    }
                }
                x=max(x,reall);
            }
            else{
                ll suff[n];
                ll cnt1=arr[0];
                suff[n-1]=abs(arr[n-1]);
                ll reall = accumulate(arr+1,arr+n,0ll);
                for(int i=n-2;i>=0;i--){
                    suff[i]=abs(arr[i])+suff[i+1];
                }
                for(int i=1;i<n;i++){
                    if(arr[i]<0)x=x+abs(arr[i]);
                    else {
                        if(suff[i]+cnt >=real[i] ){
                            x=x+cnt1+suff[i]-arr[n-1];
                            break;
                        }
                        else {
                            x=x-arr[i];
                            continue;
                        }
                    }
                }
                reall=-reall;
                x=max(x,reall);
            }
        }
        cout<<x<<endl;
        
    }
    return 0;
    }
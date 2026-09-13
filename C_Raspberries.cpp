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
        ll arr[n];
        ll zeroer=0;
        ll mn = 6;
        ll oddcnt=0,evencnt=0;
        ll prod=1;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2==0)evencnt++;
            else oddcnt++;
        }
        for(int i=0;i<n;i++){
            if(arr[i]%k==0){
                mn=0;
                break;
            }
            else if(arr[i]%k!=0){
                x=arr[i]/k;
                r=(x+1)*k-arr[i];
                mn=min(r,mn);
            }
        }
        if(evencnt==0 and k==4){
            cout<<min(mn,2ll)<<endl;
        }
        else if(evencnt==1 and k==4){
            cout<<min(mn,1ll)<<endl;
        }
        else if(evencnt>1 and k==4){
            cout<<0<<endl;
        }
        else cout<<mn<<endl;
    }
    return 0;
    }
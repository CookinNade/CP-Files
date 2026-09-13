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
        ll arr[n];
        ll evencnt=0; int oddcnt=0;
        unordered_set<ll>bro;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2==1 and oddcnt==0){
                oddcnt++;
            }
            if(arr[i]%2==0 and evencnt==0){
                evencnt++;
            }
        }
        ll vangar;
        if(evencnt>0 and oddcnt>0){
            cout<<2<<endl;
        }
        else if(oddcnt==0 or evencnt==0){
            for(int j=2;j<=57;j++){
                vangar = 1ll<<j;
                bro.clear();
                for(int i=0;i<n;i++){
                    bro.insert(arr[i]%vangar);
                    if(bro.size()>2){
                        break;
                    }
                }
                if(bro.size()==2){
                    cout<<vangar<<endl;
                    break;
                }
            }
        }

    }
    return 0;
    }
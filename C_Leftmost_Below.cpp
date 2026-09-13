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
        for(int i=0;i<n;i++)cin>>arr[i];
        ll chk = arr[0]; int noer=0;
        for(int i=1;i<n;i++){
            if(arr[i]<chk){
                chk=arr[i];
            }
            else if(arr[i]<chk*2) continue;
            else{
                noer++;
                break;
            }
        }
        cout<<(noer>0?"NO\n":"YES\n");

        
    }
    return 0;
    }
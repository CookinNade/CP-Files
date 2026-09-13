#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n];
        cnt=0;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if((arr[j]%arr[i])%2==0 ){
                    cnt++;
                    a=arr[i];b=arr[j];
                    break;
                }
            }
            if(cnt)break;
        }
        if(cnt)cout<<a<<" "<<b<<endl;
        else cout<<-1<<endl;   
    }
    return 0;
    }
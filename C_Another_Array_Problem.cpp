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
        if(n==2){
            m = max(abs(arr[0]-arr[1])*2 , arr[0]+arr[1]);
            cout<<m<<endl;
        }
        else if(n==3){
            ll take1[3]; take1[0]=arr[0],take1[1]=arr[1],take1[2]=arr[2];
            m = accumulate(take1,take1+3,0ll);
            // cout<<m<<" 0"<<endl;
            take1[0]=abs(arr[1]-arr[0]);
            take1[1]=abs(arr[1]-arr[0]);
            take1[2]=abs(arr[2]-take1[1]);
            m = max(m,accumulate(take1,take1+3,0ll));
            // cout<<m<<" 1"<<endl;
            take1[0]=arr[0],take1[1]=arr[1],take1[2]=arr[2];
            take1[2]=abs(arr[2]-arr[1]);
            take1[1]=abs(arr[2]-arr[1]);
            take1[0]=abs(arr[1]-take1[0]);
            m = max(m,accumulate(take1,take1+3,0ll));
            // cout<<m<<" 2"<<endl;
            take1[0]=arr[0],take1[1]=arr[1],take1[2]=arr[2];
            take1[0]=abs(arr[1]-arr[0]);
            take1[1]=abs(arr[1]-arr[0]);
            m = max(m,take1[0]*3);
            m = max(m,take1[2]*3);
            m = max(m,accumulate(take1,take1+3,0ll));
            // cout<<m<<" 3"<<endl;
            take1[0]=arr[0],take1[1]=arr[1],take1[2]=arr[2];
            take1[2]=abs(arr[2]-arr[1]);
            take1[1]=abs(arr[2]-arr[1]);
            m = max(m,take1[0]*3);
            m = max(m,take1[2]*3);
            m = max(m,accumulate(take1,take1+3,0ll));
            // cout<<m<<" 4"<<endl;
            m = max(m,arr[0]*3);
            // m = max(m,take1[0]*3);
            // m = max(m,take3[0]*3);
            // cout<<m<<" 5"<<endl;
            m = max(m,arr[2]*3);
            // cout<<m<<" 6"<<endl;
            cout<<m<<endl;
        }
        else{
            cout<<(*max_element(arr,arr+n))*n<<endl;
        }
    }
    return 0;
    }
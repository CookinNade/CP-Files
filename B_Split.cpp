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
    ll s;
    while (t--){
        cin>>n;
        ll arr[2*n];
        map<ll,ll>mp;
        int oddcnt=0;
        s=0;
        for(int i=0;i<2*n;i++){
            cin>>arr[i];
            mp[arr[i]]++;
            s=s+arr[i];
        }
        cnt=0;
        
        for(auto it=mp.begin();it!=mp.end();++it){
            if((*it).second%2)oddcnt++;
            if((*it).second%2)cnt++;
            else cnt=cnt+2;
        }
        if(oddcnt)cout<<cnt<<endl;
        else if(n%2){
            if(mp.size()%2)cout<<cnt<<endl;
            else cout<<cnt-2<<endl;
        }
        else{
            if(mp.size()%2)cout<<cnt-2<<endl;
            else cout<<cnt<<endl;
        }

    }
    return 0;
    }
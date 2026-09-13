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
        cin>>n>>k;
        unordered_map<char,int>mp;
        int len =0;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int l=0,i=0;i<n;i++){
            if(mp.find(arr[i])==mp.end() and mp.size()<2){
                mp[arr[i]]=i;
                len = max(len,i-l+1);    
            }
            else if(mp.find(arr[i])==mp.end() and mp.size()>=2){
                mp[arr[i]]=i;
                for(;mp.size()>2;l++){
                    if(l!=mp[arr[l]]){
                        continue;
                    }
                    else mp.erase(arr[l]);
                }
            }
            else if(mp.find(arr[i])!=mp.end()){
                mp[arr[i]]=i;
                len = max(len,i-l+1);
            }
        }
        cout<<len<<endl;
    }
    return 0;
}
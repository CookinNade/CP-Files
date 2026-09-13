#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n>>m;
    int arr[n];
    int barr[n]; map<int,int>mp;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<m;i++){
        cin>>a;
        mp[a]++;
    }
    for(int i=0;i<n;i++){
        if(mp.find(arr[i])!=mp.end() and mp[arr[i]]!=0){
            mp[arr[i]]--;
            arr[i]=-1;
        }
        else continue;
    }
    for(int i=0;i<n;i++){
        if(arr[i]==-1)continue;
        else cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
    }
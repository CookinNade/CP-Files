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
        cin>>n>>x;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<ll>v;
        sort(arr,arr+n);
        l=0;r=n-1; ll cur=0;
        cnt=0;
        while(true){
            // cout<<l<<" "<<r<<endl;
            if(l==r){
                cur=cur+arr[l];
                if(cur>=x)cnt=cnt+arr[l];
                cur=cur%x;
                v.push_back(arr[l]);
                break;
            }
            
            if(cur+arr[r]>=x){
                cur=cur+arr[r];
                cur=cur%x;
                cnt=cnt+arr[r];
                v.push_back(arr[r]);
                r--;
            }
            else{
                cur=cur+arr[l];
                if(cur>=x)cnt=cnt+arr[l];
                cur=cur%x;
                v.push_back(arr[l]);
                l++;
            } 
        }
        cout<<cnt<<endl;
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
    }
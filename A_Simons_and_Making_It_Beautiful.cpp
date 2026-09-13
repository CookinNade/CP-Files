#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++){
            if(arr[i]==n){
                swap(arr[0],arr[i]);
            }
        }
        for(auto x:arr)cout<<x<<" ";
        cout<<endl;
    }
    return 0;
    }
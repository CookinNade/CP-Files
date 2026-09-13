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
        cin>>n>>x;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int gap1=(x-arr[n-1])*2;
        int gap2=arr[0];
        int gap=max(gap1,gap2);
        for(int i=1;i<n;i++){
            gap=max(gap,arr[i]-arr[i-1]);
        }
        cout<<gap<<endl;
    }
    return 0;
    }
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
    int s;
    while (t--){
        cin>>n>>s;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int delmin=s-arr[0];
        int delmax=arr[n-1]-s;
        int mn=min(delmin,delmax);
        int mx=max(delmin,delmax);
        if(s>=arr[n-1]){
            cout<<s-arr[0]<<endl;
        }
        else if(s<=arr[0]){
            cout<<arr[n-1]-s<<endl;
        }
        else cout<<2*mn+mx<<endl;
    }
    return 0;
    }
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
        int arr[n+1];
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        int tr=1;
        d=arr[1]-arr[2];
        for(int i=1;i<n;i++){
            if(d!=arr[i]-arr[i+1]){
                tr--;
                break;
            }
        }
        int y=(2*arr[1]-arr[2])/(n+1);
        int x=arr[1]-n*y;
        // cout<<"this is x "<<x<<endl<<"this is y "<<y<<endl;
        for(int i=1;i<=n;i++){
            if(arr[i]==x*i+y*(n-i+1)){
                continue;
            }
            else{
                tr--;
                break;
            }
        }
        if(tr<1 or x<0 or y<0){
            cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
    return 0;
    }
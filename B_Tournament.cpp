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
        int j,onner=0;
        cin>>n>>j>>k;
        int arr[n+1];
        for(int i=1;i<=n;i++)cin>>arr[i];
        int man=arr[j];
        sort(arr+1,arr+n+1);
        if (arr[n]==man){
            onner++;
        }
        if(k==1){
            if (onner>0){
                cout<<"YES\n";
            }
            else cout<<"NO\n";
        }
        else if(k>=2){
            cout<<"YES\n";
        }
    }
    return 0;
    }
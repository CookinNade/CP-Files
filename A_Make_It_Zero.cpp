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
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr,arr+n);
        int smol = arr[0];
        int bog = arr[n-1];
        for(int i=0;i<n;i++){
            if(arr[i]!=smol){
                l=i+1;
                break;
            }
        }
        for(int i=n-1;;i--){
            if(arr[i]!=bog){
                r=i+1;
                break;
            }
        }
        cout<<l<<" "<<r<<endl;

    }
    return 0;
    }
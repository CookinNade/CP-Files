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
        int arr[n]; cnt=0;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=1;i<n;i++){
            if(gcd(arr[i],arr[i-1])==abs(arr[i]-arr[i-1]))cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
    }
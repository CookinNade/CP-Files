#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x,checker,noer; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>m;
        int arr[n*m+1];
        int ans[n];
        for(int i=0;i<n*m;i++){
            cin>>arr[i];
        }
        
        for(int i=0;i<n;i++){
            noer=0;
            for(int j=i*m;j<i*m+m;j++){
                if(j==i*m){
                    checker=arr[i*m]%n;
                    ans[arr[i*m]%n]=i+1;
                }
                else if(arr[i*m]%n==arr[i*m+1]%n)continue;
                else {
                    noer++;
                    break;
                }
            }
        }
        if(noer>0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
    }
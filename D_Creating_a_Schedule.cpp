#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,a,b,c,d,cnt,r,l,k,x;
    ll m;
    cin>>t;
    string s;
    while (t--){
        cin>>n>>m;
        int arr[m];
        for(int i=0;i<m;i++){
            cin>>arr[i];
        }
        sort(arr,arr+m);
        // if(n>1){
            for(int i=0;i<(n/2 + n%2);i++){
                if(n-i*2>1 or n==2){
                    for(int j=0; j<6;j++){
                        if(j%2==0){
                            cout<<arr[i]<<" ";
                        }
                        else cout<<arr[m-i-1]<<" ";
                    }
                    
                    cout<<endl;
                    for(int j=0; j<6;j++){
                        if(j%2==0){
                            cout<<arr[m-i-1]<<" ";
                        }
                        else cout<<arr[i]<<" ";
                    }
                    cout<<endl;
                }
                else {
                    for(int j=0; j<6;j++){
                        if(j%2==0){
                            cout<<arr[i]<<" ";
                        }
                        else cout<<arr[m-i-1]<<" ";
                    }
                    cout<<endl;
                }
            }
        // }
        // else {
        //     for(int j=0; j<6;j++){
        //         cout<<arr[0]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    return 0;
    }
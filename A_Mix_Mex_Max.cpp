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
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }int num = arr[0];
        for(int i=0;i<n;i++){
            if(num == -1)num = arr[i];
        }
        int noer=0;
        for(int i=0;i<n;i++){
            if(num==arr[i] or arr[i]==-1) continue;
            else {
                noer++;break;
            }
        }
        if(num==0 or noer){cout<<"NO\n";}
        else cout<<"YES\n";

    }
    return 0;
    }
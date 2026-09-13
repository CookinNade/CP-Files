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
        cin>>k>>n;
        int arr[k+1]={0};
        for(int i=0;i<n;i++){
            cin>>a;
            for(int j=1;j*a<=k;j++){
                arr[j*a]++;
            }
        }
        int ans=0;
        for(int i=1;i<=k;i++){
            // cout<<arr[i]<<" ";
            if(i%7==0 or i%7==6)continue;
            else if(arr[i])ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
    }
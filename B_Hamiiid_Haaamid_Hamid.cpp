#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>x;
        char c;
        char arr[n+1];
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        int left=-1;int right=-1;
        for(int i=1;i<x;i++){
            if(arr[i]=='#') left =i;
        }
        for(int i=x+1;i<=n;i++){
            if(arr[i]=='#'){
                right = n-i+1;
                break;
            }
        }
        if((left==-1 and right ==-1) or (x==n or x==1))cout<<1<<endl;
        else if(right>left)cout<<min(x,right+1)<<endl;
        else if(left>right) cout<<min(left+1,n-x+1)<<endl;
        else cout<<right+1<<endl;
    }
    return 0;
    }
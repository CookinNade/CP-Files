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
        vector<ll>v;
        for(int i=0;i<n;i++){
            cin>>a;
            v.push_back(a);
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
           for(int j=i-1;j>=0;j--){
                if(v[j]>v[i]){
                    cnt++;
                    break;
                }
           } 
        }
        cout<<cnt<<endl;
    }
    return 0;
    }
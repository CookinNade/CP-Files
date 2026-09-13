#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x;
    string dig1,dig2;
    cin>>n; int ans=10000; 
    for(int i=1;i<n;i++){
        b=n-i;
        int sum=0;
        dig1= to_string(i); dig2=to_string(b);
        for(int j=0;j<dig1.size();j++){
            int yo =(dig1[j]-'0');
            sum= sum+yo;
        }
        for(int j=0;j<dig2.size();j++){
           int yo =(dig2[j]-'0');
            sum= sum+yo;
        }
        ans=min(sum,ans);
    }
    cout<<ans<<endl;
    return 0;
    }
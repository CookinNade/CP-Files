#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k>>s;
        ll freq[k][26];
        for(int i=0;i<k;i++){
            for(int j=0;j<26;j++)freq[i][j]=0;
        }
        for(int i=0;i<n;i++){
            freq[i%k][s[i]-'a']++;
        }
        ll ans=0;
        for(int i=0;i<k/2;i++){
            cnt=0;
            for(int j=0;j<26;j++){
                cnt=max(cnt,freq[i][j]+freq[k-i-1][j]);
            }
            // cout<<i<<" "<<cnt<<endl;
            ans=ans+(n/k)*2-cnt;
        }
        if(k%2){
            cnt=0;
            for(int j=0;j<26;j++){
                cnt=max(cnt,freq[k/2][j]);
            }
            ans=ans+(n/k)-cnt;
        }
        cout<<ans<<endl;
    }
    return 0;
    }
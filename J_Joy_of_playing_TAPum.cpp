#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 1001;
int arr[N];
int dp[N][N][8];
int n;
int pref[N][3];
int hobe(int i, int r, int k){
    // cout<<"dhukse "<<i<<" "<<r<<" "<<k<<endl;
    if(i >= r)return 1;
    if(dp[i][r][k]!=-1)return dp[i][r][k];
    int cnt0 = pref[r][0] - pref[i-1][0];
    if((k & (1<<0)))cnt0++;
    int cnt1 = pref[r][1] - pref[i-1][1];
    if((k & (1<<1)))cnt1++;
    int cnt2 = pref[r][2] - pref[i-1][2];
    if((k & (1<<2)))cnt2++;
    if(cnt1!=cnt2 or cnt1!=cnt0){
        // cout<<"baad at "<<i<<" "<<r<<" "<<k<<endl; 
        return dp[i][r][k] = 0;
    }
    int way = 0;
    int kbefore = k;
    k |= (1<<arr[i]);
    if(k >= 7 and i!=r) way = max(way, hobe(i+1, r, 0));
    if(i!=n and !(k & (1<<arr[i+1]))) way = max(way, hobe(i+1, r, k));
    for(int j = i+4; j<=r; j+=3){
        if(!(k & (1<<arr[j]))){
            if(hobe(i+1,j-1,0) and hobe(j,r,k)) {
                way = 1;
                break;
            }
        }
    }
    return dp[i][r][kbefore] = way;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    n = (int)s.size();
    memset(dp,-1,sizeof(dp));
    
    for(int i=1;i<=n;i++){
        if(s[i-1]=='A'){
            arr[i] = 0;
            pref[i][0] = 1;
        }
        if(s[i-1]=='P'){
            arr[i] = 1;
            pref[i][1] = 1;
        }
        if(s[i-1]=='T'){
            arr[i] = 2;
            pref[i][2] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++)pref[i][j] += pref[i-1][j];
    }
    // for(int i=0;i<=n;i++)cout<<pref[i][0]<<" ";
    // cout<<endl;
    // for(int i=0;i<=n;i++)cout<<pref[i][1]<<" ";
    // cout<<endl;
    // for(int i=0;i<=n;i++)cout<<pref[i][2]<<" ";
    // cout<<endl;

    // for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    if(hobe(1,n,0))cout<<'S';
    else cout<<'N';

    return 0;
    }
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        string s;
        cin>>s;
        int one[n];
        int zero[n];
        fill(one,one+n,0);
        fill(zero,zero+n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='1')one[i]++;
            else zero[i]++;
        }
        for(int i=1;i<n;i++)one[i] += one[i-1];
        for(int i=n-2;i>=0;i--)zero[i] += zero[i+1];
        int ans = min(one[n-1],zero[0]);
        for(int i=0;i<n-1;i++){
            ans = min(ans, one[i] + zero[i+1]);
        }
        int cnt = 0;
        if(s[0] == '1'){
            for(int i=0;i<n;i++)if(s[i] == '0')cnt++;
            cout<<cnt<<'\n';
            continue;
        }
        cout<<ans<<'\n';
    }
    return 0;
    }
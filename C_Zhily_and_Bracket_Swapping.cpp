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
        int a[n];
        int b[n];
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='(') a[i] = 1;
            else a[i] = -1;
        }
        cin>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='(') b[i] = 1;
            else b[i] = -1;
        }
        int ab[n] , aa[n];
        fill(ab,ab+n,2);
        fill(aa,aa+n,2);
        for(int i=0;i<n;i++){
            if(a[i]==b[i]){
                ab[i]=a[i];
                aa[i]=a[i];
            }
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                if(cnt%2){
                    aa[i] = 1;
                    ab[i] = -1;
                    cnt++;
                }
                else{
                    ab[i] = 1;
                    aa[i] = -1;
                    cnt++;
                }
            }
        }
        int yes=true;
        int ans=0;
        for(int i=0;i<n;i++){
            ans += aa[i];
            if(ans<0) yes = false;
        }
        if(ans!=0) yes = false;
        
        ans = 0;

        for(int i=0;i<n;i++){
            ans += ab[i];
            if(ans<0) yes = false;
        }
        if(ans!=0) yes = false;
        if(yes)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
    }
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        ll pref[n];
        ll suff[n];
        suff[n-1]=arr[n-1];
        pref[0]=arr[0];
        for(int i=1;i<n;i++) pref[i]=arr[i] ^ pref[i-1];
        for(int i=n-2;i>=0;i--) suff[i]= suff[i+1] ^ arr[i];
        int yes=0;
        for(int i=0;i<n-1;i++)if(pref[i]==suff[i+1])yes++;
        if(yes){
            cout<<"YES\n";
            continue;
        }
        for(int i=0;i<n-1;i++){
            a=pref[i];
            for(int j=n-1;j>i;j--){
                if(a==suff[j]){
                    ll num = pref[j-1];
                    num = num ^ pref[i];
                    if(num==suff[j]){
                        yes++;
                        break;
                    }  
                }
            }
            if(yes)break;
        }
        if(yes)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    }
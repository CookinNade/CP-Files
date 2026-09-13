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
        string a,b;
        cin>>a>>b;
        if(a==b){
            cout<<"YES\n";
            continue;
        }
        bool yes = false;
        for(int i=0;i<n-1;i++){
            if(a[i] == a[i+1]){
                yes = true;
                break;
            }
        }
        int cnta = 0, cntb = 0;
        for(int i = 0; i<n;i+=2){
            if(a[i] == '1')cnta++;
            if(b[i] == '1')cntb++;
        }
        if(cnta!=cntb){
            cout<<"NO\n";
            continue;
        }
        for(int i = 1; i<n;i+=2){
            if(a[i] == '1')cnta++;
            if(b[i] == '1')cntb++;
        }
        if(cnta!=cntb){
            cout<<"NO\n";
            continue;
        }
        if(yes)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    }
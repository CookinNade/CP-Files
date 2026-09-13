#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        string a,b;
        cin>>a>>b;
        if(a==b){
            cout<<"0\n";
            continue;
        }
        bool yes = false;
        for(int i=0;i<n-1;i++){
            if(a[i] == a[i+1]){
                yes = true;
                break;
            }
        }
        ll cnta = 0, cntb = 0;
        for(int i = 0; i<n;i+=2){
            if(a[i] == '1')cnta++;
            if(b[i] == '1')cntb++;
        }
        if(cnta!=cntb){
            cout<<"-1\n";
            continue;
        }
        for(int i = 1; i<n;i+=2){
            if(a[i] == '1')cnta++;
            if(b[i] == '1')cntb++;
        }
        if(cnta!=cntb or !yes){
            cout<<"-1\n";
            continue;
        }
        
        set<ll>st1;
        set<ll>st0;
        cnta = 0;
        for(int i=0;i<n;i+=2)if(a[i]=='1')st1.insert(i);
        for(int i=0;i<n;i+=2)if(a[i]=='0')st0.insert(i);
        for(int i=0;i<n;i+=2){
            if(a[i]=='0' and b[i]=='1'){
                auto it = st1.upper_bound(i);
                ll ind = (*it) - i;
                ll val = (*it);
                swap(a[i],a[val]);
                st1.erase(val);
                st0.insert(val);
                ind /= 2;
                cnta+=ind;
                continue;
            }
            if(a[i]=='1' and b[i]=='0'){
                auto it = st0.upper_bound(i);
                ll val = (*it);
                ll ind = val - i;
                swap(a[i],a[val]);
                st0.erase(val);
                st1.insert(val);
                ind /= 2;
                cnta+=ind;
            }
        }

        st1.clear();
        st0.clear();

        for(int i=1;i<n;i+=2)if(a[i]=='1')st1.insert(i);
        for(int i=1;i<n;i+=2)if(a[i]=='0')st0.insert(i);
        for(int i=1;i<n;i+=2){
            if(a[i]=='0' and b[i]=='1'){
                auto it = st1.upper_bound(i);
                int ind = (*it) - i;
                int val = (*it);
                swap(a[i],a[val]);
                st1.erase(val);
                st0.insert(val);
                ind /= 2;
                cnta+=ind;
                continue;
            }
            if(a[i]=='1' and b[i]=='0'){
                auto it = st0.upper_bound(i);
                ll ind = (*it) - i;
                ll val = (*it);
                swap(a[i],a[val]);
                st0.erase(val);
                st1.insert(val);
                ind /= 2;
                cnta+=ind;
            }
        }
        cout<<cnta<<'\n';
        
    }
    return 0;
    }
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
        int arr[n];
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cnt = 1;
        int a = arr[0];
        for(int i=1;i<n;i++){
            if(a == arr[i])cnt++;
            else{
                v.push_back({a,cnt});
                a = arr[i];
                cnt = 1;
            }
        }
        v.push_back({a,cnt});
        int adder = 0;
        int sz = (int)v.size();
        for(int i=0;i<sz - 1; i++){
            if(v[i].second >= 2 and v[i+1].second >= 2){
                adder =2;
                break;
            }
            if(v[i].second == 1 and v[i+1].second >= 2){
                int d;
                if(i==0) d = n+1;
                else d = v[i-1].first;
                if(d == v[i+1].first)continue;
                adder = 1;
            }
            if(v[i].second >= 2 and v[i+1].second == 1){
                int d;
                if(i==sz-2) d = n+1;
                else d = v[i+2].first;
                if(d == v[i].first)continue;
                adder = 1;
            }
        }
        cout<<(int)v.size() + adder<<'\n';
        

    }
    return 0;
    }
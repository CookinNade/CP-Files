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
        vector<ll>v(n+1);
        fill(v.begin(),v.end(),0);
        for(int i=0;i<n-1;i++){
            cin>>a;
            v[a]++;
        }
        v[0]=1;
        sort(v.rbegin(),v.rend());
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==0)
                v.pop_back();
            else break;
        }
        r=(int)v.size();
        vector<ll>arr;
        for(int i=0;i<v.size();i++){
            a=v[i]-r+i;
            if(a>0)arr.push_back(a);
        }
        while(true){
            sort(arr.rbegin(),arr.rend());
            for(int i=arr.size()-1;i>=0;i--){
                if(arr[i]<=0)
                    arr.pop_back();
                else break;
            }
            if(arr.empty()) break;
            arr[0]--;
            for(int i=0;i<arr.size();i++){
                arr[i]--;
            }
            r++;
        }
        cout<<r<<endl;
    }
    return 0;
    }
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x,ans,final; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>x;
        int arr[n];
        int dis=0;
        vector<int>v;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==1){
                v.push_back(i+1);
            }
        }
        if(v.size()>x+1){
            ans=v[x]-1;
            final = n-v[v.size()-x-1];
            ans=max(ans,final);
            for(int j=x+1,i=0;j<v.size();j++,i++){
                ans = max(ans,v[j]-v[i]-1);
            }
        }
        else if(v.size()==x+1){
            ans=max(v[x]-1,n-v[0]);
        }
        if(v.size()==x){
            cout<<0<<endl;
        }
        else if(v.size()<x){
            cout<<-1<<endl;
        }
        else cout<<n-ans<<endl;
       
        
    }
    return 0;
    }
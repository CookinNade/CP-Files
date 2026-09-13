#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>m; int arr[m];
        int mn= 100000;
        int mx=0; int cnt=0; set<int>st;
        for(int i=0;i<m;i++){
            cin>>a;
            arr[i]=a;
            mn=min(a,mn);
            mx=max(a,mx);
            if(st.find(a)!=st.end())cnt++;
            st.insert(a);
        }
        bool tr = is_sorted(arr,arr+m);
        
        if(cnt)cout<<1<<endl;
        else if(tr){
            cout<<n-mx+1<<endl;
        }
        else{
            cout<<1<<endl;
        }
    }
    return 0;
    }
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
        cin>>n;
        int arr[n];
        int ans[31]={0};
        vector<int>v;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++){
            if(!arr[i])continue;
            for(int j=0;j<=ceil(log2(arr[i]));j++) if((arr[i]>>j)&1)ans[j]++;
        }
        for(int i=1;i<=n;i++){
            int noer=0;
            for(int j=0;j<=30;j++){
                if(ans[j]%i!=0){
                    noer++;
                    break;
                }   
            }
            if(noer)continue;
            else v.push_back(i);
        }
        // for(int i=0;i<=30;i++) cout<<ans[i]<<" ";
        // cout<<"it ended here"<<endl;
        for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
        cout<<endl;
    }
    return 0;
    }
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
        cin>>n>>s;
        vector<int>v;vector<int>vv;
        v.push_back(0);
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                v.push_back(i+1);
                vv.push_back(i+1);
            }
        }
        v.push_back(n+1); int noer=0;
        for(int i=0;i<v.size()-1;i++){
            if(v[i+1]-v[i]==2){
                noer++;break;
            }
        }
        if(noer)cout<<"NO\n";
        else{
            cout<<"YES\n";
            int arr[n+1]={0};
            for(int i=0;i<vv.size();i++){
                arr[vv[i]] = vv[i];
            }
            // for(int i=1;i<=n;i++){
            //     cout<<arr[i]<<" ";
            // }cout<<endl;
            for(int i=0;i<v.size()-1;i++){
                r=v[i+1];l=v[i]; int temp=r-1;
                // cout<<r<<" "<<l<<endl;
                if(temp==n+1)temp--;
                for(int j =l+1;j<r;j++){
                    arr[j]=temp;
                    temp--;
                }
            }
            for(int i=1;i<=n;i++){
                cout<<arr[i]<<" ";
            }cout<<endl;
        }
        
    }
    return 0;
    }
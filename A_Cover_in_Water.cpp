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
        char arr[n];
        vector<int>v;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cnt=0;
        int real_cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]=='.' and i!=n-1){
                cnt++;
            }
            else if(i==n-1){
                if(arr[i]=='.') cnt++;
                v.push_back(cnt);
            }
            else if(arr[i]=='#'){
                v.push_back(cnt);
                cnt=0;
            }
        }
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<v.size();i++){
            if(v[i]>2){
                real_cnt=2;
                break;
            }
            else real_cnt=real_cnt+v[i];
        }
        cout<<real_cnt<<endl;
    }
    return 0;
    }
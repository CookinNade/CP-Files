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
        ll arr[n];
        vector<char>v;
        vector<ll>chk;
        for(int i=0;i<n;i++)cin>>arr[i];
        int l=0;r=n-1;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(arr[l]>=arr[r]){
                    v.push_back('L');
                    chk.push_back(arr[l]);
                    l++;
                }
                else {
                    v.push_back('R');
                    chk.push_back(arr[r]);
                    r--;
                }
            }
            if(i%2==1){
                if(arr[l]<=arr[r]){
                    v.push_back('L');
                    chk.push_back(arr[l]);
                    l++;
                }
                else {
                    v.push_back('R');
                    chk.push_back(arr[r]);
                    r--;
                }
            }
        }
        // for(int i=0;i<v.size();i++){
        //     cout<<chk[i]<<" ";
        // }cout<<endl;
        for(int i=0;i<v.size();i++){
            cout<<v[i];
        }cout<<endl;
    }
    return 0;
    }
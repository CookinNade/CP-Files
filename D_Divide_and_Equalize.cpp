#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x,w; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        int arr[n];
        map<int,int>mp;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++){
            for(int j=2;j*j<=arr[i];j++){
                if(arr[i]%j==0){
                    mp[j]++;
                    arr[i]=arr[i]/j;
                    j=1;
                }
            }
            if(arr[i]==1)continue;
            mp[arr[i]]++;
            // cout<<arr[i]<<" "<<endl;
        }
        int noer=0;
        for(auto it=mp.begin();it!=mp.end();++it){
            // cout<<(*it).first<<" "<<(*it).second<<endl;
            if((*it).second%n!=0){
                noer++;
            }
        }
        cout<<(noer==0? "YES\n":"NO\n");
    }
    return 0;
    }
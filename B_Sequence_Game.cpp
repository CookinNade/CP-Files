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
        vector <int> v;
        for(int i=0;i<n;i++)cin>>arr[i];
        v.push_back(arr[0]);
        for(int i=1;i<n;i++){
            v.push_back(arr[i]);
            if(arr[i]<arr[i-1]){
                v.push_back(arr[i]);
            }
        }
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
    }
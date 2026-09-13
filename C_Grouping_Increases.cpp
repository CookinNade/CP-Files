#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        vector<int> vs;
        vector<int> vt;
        vs.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(vt.size()==0){
                if(vs[vs.size()-1]>=arr[i]) vs.push_back(arr[i]);
                else vt.push_back(arr[i]);
            }
            else if(arr[i]<=vt[vt.size()-1] and arr[i]<=vs[vs.size()-1]){
                if(vs[vs.size()-1]>=vt[vt.size()-1]) vt.push_back(arr[i]);
                else vs.push_back(arr[i]);
            }
            else if(arr[i]>vt[vt.size()-1] and arr[i]<=vs[vs.size()-1]){
                vs.push_back(arr[i]);
            }
            else if(arr[i]>vs[vs.size()-1] and arr[i]<=vt[vt.size()-1]){
                vt.push_back(arr[i]);
            }
            else if(arr[i]>vt[vt.size()-1] and arr[i]>vs[vs.size()-1]){
                if(vs[vs.size()-1]>=vt[vt.size()-1]) vt.push_back(arr[i]);
                else vs.push_back(arr[i]);
            }
        }
        int ans =0;
        for(int i=0;i<vs.size()-1;i++)
            if(vs[i]<vs[i+1]) ans++;
        
        if(vt.size()!=0){
                for(int i=0;i<vt.size()-1;i++){
                if(vt[i]<vt[i+1]) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
    }
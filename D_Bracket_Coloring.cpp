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
        vector <pair<char,int>> v;
        int arr[n]={0};
        v.push_back({s[0],0});

        for(int i=1;i<n;i++){
            if(v.size()!=0 and v[v.size()-1].first==')' and s[i]=='('){
                arr[i]=1;
                arr[v[v.size()-1].second]=1;
                // cout<<v[v.size()-1].first<<" "<<s[i]<<" "<<i<<" "<<v[v.size()-1].second<<endl;
                v.pop_back();
                
                // cout<<"popped"<<endl;
            }
            else v.push_back({s[i],i});
        }
        int first=0;
        if(v.size()==0)first++;
        v.clear();
        fill(arr,arr+n,0);
        v.push_back({s[0],0});
        for(int i=1;i<n;i++){
            if(v.size()!=0 and v[v.size()-1].first=='(' and s[i]==')'){
                arr[i]=1;
                arr[v[v.size()-1].second]=1;
                v.pop_back();
                // cout<<"popped"<<endl;
            }
            else v.push_back({s[i],i});
        }
        int twoer=0;
        if(v.size()!=0){
            // cout<<v.size()<<endl;
            m=v.size();
            vector <pair<char,int>>vv;
            vv.push_back(v[0]);
            for(int i=1;i<m;i++){
                // cout<<v[i].first<<" "<<v[i].second;
                if(vv.size()!=0 and vv[vv.size()-1].first==')' and v[i].first=='('){
                    arr[v[i].second]=2;
                    arr[vv[vv.size()-1].second]=2;
                    vv.pop_back();
                }
                else vv.push_back(v[i]);
            }
        }
        int noer=0; int oner=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0)noer++;
            if(arr[i]==1)oner++;
            if(arr[i]==2)twoer++;
            // cout<<arr[i]<<" ";
        }
        if(first){
            cout<<1<<endl;
            for(auto x:arr){
                cout<<1<<" ";
            }cout<<endl;
        }
        else if(noer)cout<<-1<<endl;
        else if(twoer and oner){
            cout<<2<<endl;
            for(auto x:arr){
                cout<<x<<" ";
            }cout<<endl;
        }
        else{
            cout<<1<<endl;
            for(auto x:arr){
                cout<<1<<" ";
            }cout<<endl;
        }

    }
    return 0;
    }
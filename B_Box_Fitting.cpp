#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>x;
        vector<ll>v;
        for(int i=0;i<n;i++){
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        ll rem=x;
        cnt=1;
        for(;v.size()!=0;){
            auto it=lower_bound(v.begin(),v.end(),rem);
            if(it!=v.end() and (*it)==rem){
                rem=x; 
                // cout<<*it<<" from 1 \n";
                v.erase(it);
                if(v.size())cnt++;
            }
            else if((*it)>rem and it!=v.begin() and it!=v.end()){
                --it;
                // cout<<*it<<" from 2 \n";
                rem=rem-(*it);
                v.erase(it);
            }
            else if((*it)>rem and it==v.begin()){
                cnt++;
                // cout<<*it<<" from 3 \n";
                rem=x;
            }
            else if(it==v.end()){
                --it; 
                // cout<<*it<<" from 4 \n";
                rem=rem-(*it);
                // cout<<"this was rem "<<rem<<endl;
                v.erase(it);
            }
            
        }
        cout<<cnt<<endl;

    }
    return 0;
    }
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n>>m;
    map<int,int>mp;
    for(int i=0;i<n;i++) {
        cin>>a;
        mp[a]++;
    }
    for(int i=0;i<m;i++){
        cin>>a;
        auto it = mp.lower_bound(a);
        if(((*it).first)>a and it!=mp.end()){
            if(it==mp.begin())cout<<-1<<endl;
            else {
                --it;
                cout<<(*it).first<<endl;
                mp[(*it).first]--;
                if((*it).second==0) mp.erase((*it).first);
            }
        }
        else if(it==mp.end()){
            if(mp.size()==0)cout<<-1<<endl;
            else{
                --it;
                cout<<(*it).first<<endl;
                mp[(*it).first]--;
                if((*it).second==0) mp.erase((*it).first);
            }
        }
        else{
            cout<<(*it).first<<endl;
            mp[(*it).first]--;
            if((*it).second==0) mp.erase((*it).first);
        }
    }
    return 0;
    }
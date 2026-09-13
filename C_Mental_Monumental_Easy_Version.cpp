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
        map<int,int>mp;
        map<int,int>dm;
        for(int i=0;i<n;i++){
            cin>>a;
            mp[a]++;
        }
        int hi=n,lo=0,mid;
        while(hi-lo>1){
            dm.clear();
            for(auto it = mp.begin();it!=mp.end();++it){
                a=(*it).first;
                b=(*it).second;
                dm[a]=b;
            }
            mid=(hi+lo)/2;
            bool yes=false;
            for(int i=mid;i>=0;i--){
                // if(i==0)cout<<i<<endl;
                if(dm.find(i)!=dm.end()){
                    dm[i]--;
                    if(dm[i]==0)dm.erase(i);
                    if(i==0){
                        yes=true;
                    }
                }
                else{
                    a=i*2;
                    auto it =dm.upper_bound(a);
                    if(it==dm.end()){
                        yes=false;
                        break;
                    }
                    else{
                        b=(*it).first;
                        dm[b]--;
                        if(dm[b]==0)dm.erase(b);
                        if(i==0){
                            yes=true;
                            
                        }
                    }
                }
            }
            if(yes)lo=mid;
            else hi=mid-1;
        }
        mid=hi;
        dm.clear();
        for(auto it = mp.begin();it!=mp.end();++it){
                a=(*it).first;
                b=(*it).second;
                dm[a]=b;
        }
        bool yes=false;
        for(int i=mid;i>=0;i--){
            if(dm.find(i)!=dm.end()){
                dm[i]--;
                if(dm[i]==0)dm.erase(i);
                if(i==0)yes=true;
            }
            else{
                a=i*2;
                auto it =dm.upper_bound(a);
                if(it==dm.end()){
                    yes=false;
                    break;
                }
                else{
                    b=(*it).first;
                    dm[b]--;
                    if(dm[b]==0)dm.erase(b);
                    if(i==0)yes=true;
                }
            }
        }
        if(yes)cout<<mid+1<<endl;
        else cout<<lo+1<<endl;
    }
    return 0;
    }
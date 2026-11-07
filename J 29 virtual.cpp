#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define double long double

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(8);
    map<int,double> mp;
    int ind = 1;
    mp[0] = 2.0;
    double cnt = 1;
    for(int i=0;i<5;i++){
        mp[ind] = cnt;
        ind *= 2;
        cnt /= 2.0;
    }
    int n;
    cin>>n;
    double ans = 0;
    // for(auto it = mp.begin();it!=mp.end();++it){
    //     cout<<(*it).first<<" "<<(*it).second<<endl;
    // }
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        ans += mp[a];
    }
    cout<<ans;
    
    return 0;
    }
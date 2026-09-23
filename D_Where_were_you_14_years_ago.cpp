#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int que(int i, int j){
    cout<<"? "<<2<<" "<<i<<" "<<j<<endl;
    int ans;
    cin>>ans;
    return ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int f[n+1];
    int s[n+1];
    bool vis[3];
    fill(vis,vis+3,false);
    for(int i=2;i<=n;i++){
        int ans = que(1,i);
        vis[ans] = true;
        f[i] = ans;
    }
    int sum = 0;
    for(int i=0;i<3;i++){
        if(vis[i]) sum += i;
    }
    if(sum == 1){
        f[1] = 0;
        int j = 2;
        for(int i=2;i<=n;i++){
            if(f[i] == 1){
                j = i;
                break;
            }
        }
        for(int i=2;i<=n;i++){
            if(i == j)continue;
            s[i] = que(j,i);
        }
        cout<<"! F";
        for(int i=2;i<=n;i++){
            if(i == j){
                cout<<'T';
                continue;
            }
            if(f[i] == 0 and s[i] == 2)cout<<'M';
            if(f[i] == 1 and s[i] == 2)cout<<'T';
            if(f[i] == 0 and s[i] == 1)cout<<'F';
        }
        cout<<endl;
    }
    if(sum == 3){
        f[1] = 2;
        int j = 2;
        for(int i=2;i<=n;i++){
            if(f[i] == 1){
                j = i;
                break;
            }
        }
        for(int i=2;i<=n;i++){
            if(i == j)continue;
            s[i] = que(j,i);
        }
        cout<<"! T";
        for(int i=2;i<=n;i++){
            if(i == j){
                cout<<'F';
                continue;
            }
            if(s[i] == 0 and f[i] == 2)cout<<'M';
            if(s[i] == 1 and f[i] == 2)cout<<'T';
            if(s[i] == 0 and f[i] == 1)cout<<'F';
        }
        cout<<endl;
    }
    if(sum == 2){
        f[1] = 0;
        int j = 2;
        for(int i=2;i<=n;i++){
            if(f[i] == 2){
                j = i;
                break;
            }
        }
        for(int i=2;i<=n;i++){
            if(i == j)continue;
            s[i] = que(j,i);
        }
        cout<<"! M";
        for(int i=2;i<=n;i++){
            if(i == j){
                cout<<'T';
                continue;
            }
            if(f[i] == 2)cout<<'T';
            if(s[i] == 1 and f[i] == 0)cout<<'F';
            if(s[i] == 2 and f[i] == 0)cout<<'M';
        }
        cout<<endl;
    }
    return 0;
    }
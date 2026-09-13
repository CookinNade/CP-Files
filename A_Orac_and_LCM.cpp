#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=2e5;
 
int main () {
    int n,a,b,c,cnt;
    cin>>n;
    int siv[N+2];
    bool vis[N+2];
    fill(vis,vis+N+1,false);
    for(int i=2;i<=N;i++){
        if(vis[i])continue;
        vis[i]=true;
        for(int j=i;j<=N;j=j+i){
            siv[j]=i;
            vis[j]=true;
        }
    }
    ll hobe[N+1];
    fill(hobe,hobe+N,0);
    pair<int,int>ans[N+1];
    for(int i=2;i<=N;i++)ans[i]={1000,1000};
    for(int i=0;i<n;i++){
        cin>>a;
        while(a>1){
            cnt=0;
            c=siv[a];
            while(a%c==0){
                cnt++;
                a=a/c;
            }
            hobe[c]++;
            int mxcnt =  ans[c].first;
            ans[c].first=min(mxcnt,cnt);
            cnt=max(mxcnt,cnt);
            mxcnt=ans[c].second;
            ans[c].second=min(mxcnt,cnt);
            cnt=max(mxcnt,cnt);
        }
    }
    ll uttor=1;
    for(ll i=2;i<=200000;i++){
        if(hobe[i]<n-1)continue;
        if(hobe[i]==n-1){
            for(int j=0;j<ans[i].first;j++){
                uttor=uttor*i;
            }
        }
        else{
            for(int j=0;j<ans[i].second;j++){
                uttor=uttor*i;
            }
        }
    }
    cout<<uttor<<endl;
    return 0;
    }
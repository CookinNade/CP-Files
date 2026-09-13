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
        int test1[n]={2}; int test2[n]={2};
        int mx=-1; int mn=n+5;
        int noer=0; int ind=-1; int bk=-1;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mx=max(mx,arr[i]); mn = min(arr[i],mn);
            if(i==0)continue;
            if(abs(arr[i]-arr[i-1]>1)){
                noer++;
            }
            if((arr[i]-arr[i-1])==1) ind =i;
            if ((arr[i]-arr[i-1])==-1) bk =i;
            if(i==1) continue;
            if(arr[i]-arr[i-1]==1 and arr[i-2]-arr[i-1]==1)noer++;
            if(arr[i]-arr[i-1]==-1 and arr[i-2]-arr[i-1]==-1)noer++;
        }
        if(noer)cout<<0<<endl;
        else if(mx==mn){
            int rcnt=0; int lcnt=0; int ans =0;
            for(int i=0;i<n;i++){
                if(i%2) test1[i] =1;
                else test1[i]=0;
                if(i%2)rcnt++;
            }
            for(int i=0;i<n;i++){
                if(test1[i]){
                    if(rcnt+lcnt==arr[i])rcnt--;
                    else {
                        noer++; break;
                    }
                }
                else{
                    lcnt++;
                    if(rcnt+lcnt==arr[i])continue;
                    else {
                        noer++; break;
                    }
                }
            }
            if(noer==0) ans++;
            noer=0;lcnt=0; rcnt=0;
            for(int i=0;i<n;i++){
                if(i%2) test1[i] =0;
                else {
                    test1[i]=1;
                    rcnt++;
                }
            }
            for(int i=0;i<n;i++){
                if(test1[i]){
                    if(rcnt+lcnt==arr[i])rcnt--;
                    else {
                        noer++; break;
                    }
                }
                else{
                    lcnt++;
                    if(rcnt+lcnt==arr[i])continue;
                    else {
                        noer++; break;
                    }
                }
            }
            if(noer)cout<<0<<endl;
            else cout<<2<<endl;
        }
        else{
            if(ind !=-1){
                test1[ind]=0; test1[ind-1]=0;
                for(int i=ind;i>=1;i--){
                    if(arr[i]==arr[i-1]){
                        if(test1[i]) test1[i-1]=0;
                        else test1[i-1]=1;
                    }
                    else if(arr[i]-arr[i-1]==1){
                        test1[i]=0;
                        test1[i-1]=0;
                    }
                    else {
                        test1[i]=1;
                        test1[i-1]=1;
                    }
                }
                for(int i=ind;i<n-1;i++){
                    if(arr[i]==arr[i+1]){
                        if(test1[i]) test1[i+1]=0;
                        else test1[i+1]=1;
                    }
                    else if(arr[i]-arr[i+1]==1){
                        test1[i]=1;
                        test1[i+1]=1;
                        
                    }
                    else if(arr[i]-arr[i+1]==-1){
                        test1[i]=0;
                        test1[i+1]=0; 
                    }
                }
            }
            else{
                test1[bk]=1; test1[bk-1]=1;
                for(int i=bk;i>=1;i--){
                    if(arr[i]==arr[i-1]){
                        if(test1[i]) test1[i-1]=0;
                        else test1[i-1]=1;
                    }
                    else if(arr[i]-arr[i-1]==1){
                        test1[i]=0;
                        test1[i-1]=0;
                    }
                    else {
                        test1[i]=1;
                        test1[i-1]=1;
                    }
                }
                for(int i=bk;i<n-1;i++){
                    if(arr[i]==arr[i+1]){
                        if(test1[i]) test1[i+1]=0;
                        else test1[i+1]=1;
                    }
                    else if(arr[i]-arr[i+1]==1){
                        test1[i]=1;
                        test1[i+1]=1;
                        
                    }
                    else if(arr[i]-arr[i+1]==-1){
                        test1[i]=0;
                        test1[i+1]=0; 
                    }
                }
            }
            int lcnt=0;
            int rcnt=0;
            for(int i=0;i<n;i++) if(test1[i])rcnt++;
            for(int i=0;i<n;i++){
                if(test1[i]){
                    if(rcnt+lcnt==arr[i])rcnt--;
                    else {
                        noer++; break;
                    }
                }
                else{
                    lcnt++;
                    if(rcnt+lcnt==arr[i])continue;
                    else {
                        noer++; break;
                    }
                }
            }
            if(noer)cout<<0<<endl;
            else cout<<1<<endl;
        }
    }
    return 0;
    }
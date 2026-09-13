#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 32800;

const ll M=32768;

 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    t=1;
    string s;
    while (t--){
        ll time[33000];
        fill(time,time+32769,999999);
        time[32768]=0;
        queue<int>q;
        q.push(32768);
        while(!q.empty()){
            a=q.front();
            q.pop();
            int p1 = (a - 1 + 32768) % 32768;
            if(time[p1] > 20){
                q.push(p1);
                time[p1]=time[a]+1;
            }
            if(a%2==0 and a>1){
                if(time[a/2]>20){
                    q.push(a/2);
                    time[a/2]=time[a]+1;
                }
                if(time[(a + M)/2]>20){
                    time[(a + M)/2]=time[a]+1;
                    q.push((a+M)/2);
                }
            }
        }
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a;
            cout<<time[a]<<" ";        
        }
        cout<<endl;
        
    }
    return 0;
    }
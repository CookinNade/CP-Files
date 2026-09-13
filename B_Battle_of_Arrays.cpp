#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>m;
        priority_queue<ll>a;
        priority_queue<ll>b;
        for(int i=0;i<n;i++){
            cin>>c;
            a.push(c);
        }
        for(int i=0;i<m;i++){
            cin>>c;
            b.push(c);
        }
        int i=0;
        while(!a.empty() and !b.empty()){
            i++;
            if(i%2){
                c=a.top();
                d=b.top();
                b.pop();
                // cout<<i<<" "<<c<<" "<<d<<endl;
                if(c>=d)continue;
                else b.push(d-c);
                
            }
            else {
                c=a.top();
                d=b.top();
                a.pop();
                // cout<<i<<" "<<c<<" "<<d<<endl;
                if(d>=c)continue;
                else a.push(c-d);
                
            }
        }
        if(a.empty())cout<<"Bob\n";
        else cout<<"Alice\n";

    }
    return 0;
    }
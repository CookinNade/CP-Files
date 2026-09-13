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
        cin>>n>>m;
        int lo =101;
        int hi=-101;
        int grid [n][m];
        int sum=0;int summer=0;
        int negcnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a;
                sum=sum+abs(a);
                lo=min(abs(a),lo);
                hi=max(abs(a),hi);
                if(a<0)negcnt++;
                else if(a==0)summer++;
            }
        }
        if(summer>0 or negcnt%2==0)cout<<sum<<endl;
        else cout<<sum-2*lo<<endl;
    }
    return 0;
    }
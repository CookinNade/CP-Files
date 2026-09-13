#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    string s;
    cin>>n;
    int bamen[n-1]; int danen[n-1]; int dane[n-1]; int cross[n];int sum=0;
    for(int i=0;i<n-1;i++) cin>>bamen[i];
    sum=0;
    for(int i=0;i<n-1;i++) {
        cin>>danen[i];
        sum=sum+danen[i];
    }
    for(int j=0;j<n-1;j++){
        dane[j]=sum;
        sum=sum-danen[j];
    }
    for(int i=0;i<n;i++) cin>>cross[i];
    vector<int>v;
    sum=0;
    for(int i=0;i<n;i++){
        if(i==n-1) v.push_back(sum+cross[i]);
        else{
            v.push_back(cross[i]+sum+dane[i]);
            sum=sum+bamen[i];
        }
    }
    sort(v.begin(),v.end());
    cout<<v[0]+v[1]<<endl;
    return 0;
    }
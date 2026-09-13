#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
// int n;
void summer(int arr[], int n){
    // int n=arr.size();
    for(int i=1;i<n;i++)arr[i]=arr[i-1]+arr[i];
}
const ll N=2e5+1;
int a1[N],a2[N],a3[N],b1[N],b2[N],b3[N],c1[N],c2[N],c3[N];
ll finder(int b, int r, int m){
    if(b<r) return 0;
    return ((b-r)/m)+1;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,q; 
    // cin>>t;
    t=1;
    string s;
    while (t--){
        cin>>n>>q>>s;
        // int a1[n],a2[n],a3[n],b1[n],b2[n],b3[n],c1[n],c2[n],c3[n];
        fill(a1,a1+n,0);fill(a2,a2+n,0);fill(a3,a3+n,0);
        fill(c1,c1+n,0);fill(b2,b2+n,0);fill(c3,c3+n,0);
        fill(b1,b1+n,0);fill(c2,c2+n,0);fill(b3,b3+n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                if(i%3==0)a3[i]++;
                if(i%3==2)a2[i]++;
                if(i%3==1)a1[i]++;
            }
            if(s[i]=='b'){
                if(i%3==0)b3[i]++;
                if(i%3==2)b2[i]++;
                if(i%3==1)b1[i]++;
            }
            if(s[i]=='c'){
                if(i%3==0)c3[i]++;
                if(i%3==2)c2[i]++;
                if(i%3==1)c1[i]++;
            }
        }
        summer(a1,n);summer(a2,n);summer(a3,n);
        summer(b1,n);summer(b2,n);summer(b3,n);
        summer(c1,n);summer(c2,n);summer(c3,n);
        while(q--){
            cin>>a>>b;
            a--;b--;
            int f,h;
            f=finder(b,0,3); h=finder(b,2,3); c=finder(b,1,3);
            if(a!=0){
                f=f-finder(a-1,0,3); h=h-finder(a-1,2,3); c=c-finder(a-1,1,3);
            }
            int ans=n+3;
            if(a==0){
                ans=min(ans,abs(a1[b]-c) +abs(b2[b]-h) + abs(c3[b]-f));
                ans=min(ans,abs(a1[b]-c) +abs(c2[b]-h) + abs(b3[b]-f));
                ans=min(ans,abs(c1[b]-c) +abs(a2[b]-h) + abs(b3[b]-f));
                ans=min(ans,abs(b1[b]-c) +abs(a2[b]-h) + abs(c3[b]-f));
                ans=min(ans,abs(c1[b]-c) +abs(b2[b]-h) + abs(a3[b]-f));
                ans=min(ans,abs(b1[b]-c) +abs(c2[b]-h) + abs(a3[b]-f));
            }
            else{
                ans=min(ans,abs(a1[b]-a1[a-1]-c) +abs(b2[b]-b2[a-1]-h) + abs(c3[b]-c3[a-1]-f));
                ans=min(ans,abs(a1[b]-a1[a-1]-c) +abs(c2[b]-c2[a-1]-h) + abs(b3[b]-b3[a-1]-f));
                ans=min(ans,abs(b1[b]-b1[a-1]-c) +abs(c2[b]-c2[a-1]-h) + abs(a3[b]-a3[a-1]-f));
                ans=min(ans,abs(c1[b]-c1[a-1]-c) +abs(b2[b]-b2[a-1]-h) + abs(a3[b]-a3[a-1]-f));
                ans=min(ans,abs(b1[b]-b1[a-1]-c) +abs(a2[b]-a2[a-1]-h) + abs(c3[b]-c3[a-1]-f));
                ans=min(ans,abs(c1[b]-c1[a-1]-c) +abs(a2[b]-a2[a-1]-h) + abs(b3[b]-b3[a-1]-f));
            }
            cout<<ans<<endl;
        }

    }
    return 0;
    }
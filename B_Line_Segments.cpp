#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double t,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        int n;
        cin>>n;
        double x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        double arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr,arr+n);
        double dy = abs(y2-y1);
        double dx = abs(x2-x1);
        double dxx = dx*dx;
        double dyy = dy*dy;
        double dis = sqrt(dxx+dyy);
        double sum=0;
        for(int i=0;i<n-1;i++){
            sum=sum+arr[i];
        }
        // sum=sum+dis;
        // cout<<sum<<endl;
        if(n==1){
            if(dis==arr[0])cout<<"Yes\n";
            else cout<<"No\n";
        }
        else {
            if(sum+arr[n-1]>=dis and sum+min(dis,arr[n-1])>=max(dis,arr[n-1])){
                cout<<"Yes\n";
            }
            else cout<<"No\n";
        }
    }
    return 0;
    }
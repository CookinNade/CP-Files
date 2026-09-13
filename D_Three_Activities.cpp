#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x;
    int ia1,ia2,ia3,ib1,ib2,ib3,ic1,ic2,ic3;
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        int a[n]; vector<pair<int, int>> vpa;
        int b[n]; vector<pair<int, int>> vpb;
        int c[n]; vector<pair<int, int>> vpc;
        for(int i=0;i<n;i++){cin>>a[i];}
        for(int i=0;i<n;i++){cin>>b[i];}
        for(int i=0;i<n;i++){cin>>c[i];}
        int mxa1=-1;int mxa2=-1; int mxa3=-1; 
        for(int i=0;i<n;i++){
            if (mxa1<a[i]){
                mxa3=mxa2; 
                mxa2=mxa1;
                mxa1=a[i];
                ia3=ia2;
                ia2=ia1;
                ia1=i;
            }
            else if (mxa2<a[i]){
                mxa3=mxa2;
                mxa2=a[i];
                ia3=ia2;
                ia2=i;
            }
            else if (mxa3<a[i]){
                mxa3=a[i];
                ia3=i;
            }
        }
        vpa.push_back({mxa1,ia1});
        vpa.push_back({mxa2,ia2});
        vpa.push_back({mxa3,ia3});
        mxa1=-1;mxa2=-1; mxa3=-1;
        for(int i=0;i<n;i++){
            if (mxa1<b[i]){
                mxa3=mxa2; 
                mxa2=mxa1;
                mxa1=b[i];
                ib3=ib2;
                ib2=ib1;
                ib1=i;
            }
            else if (mxa2<b[i]){
                mxa3=mxa2;
                mxa2=b[i];
                ib3=ib2;
                ib2=i;
            }
            else if (mxa3<b[i]){
                mxa3=b[i];
                ib3=i;
            }
        }
        vpb.push_back({mxa1,ib1});
        vpb.push_back({mxa2,ib2});
        vpb.push_back({mxa3,ib3});
        mxa1=-1; mxa2=-1;  mxa3=-1;
        for(int i=0;i<n;i++){
            if (mxa1<c[i]){
                mxa3=mxa2; 
                mxa2=mxa1;
                mxa1=c[i];
                ic3=ic2;
                ic2=ic1;
                ic1=i;
            }
            else if (mxa2<c[i]){
                mxa3=mxa2;
                mxa2=c[i];
                ic3=ic2;
                ic2=i;
            }
            else if (mxa3<c[i]){
                mxa3=c[i];
                ic3=i;
            }
        }
        vpc.push_back({mxa1,ic1});
        vpc.push_back({mxa2,ic2});
        vpc.push_back({mxa3,ic3});
        int sum=0;
        // for(int i=0;i<vpa.size();i++)cout<<vpa[i].first<<" "<<vpa[i].second<<endl;
        // for(int i=0;i<vpa.size();i++)cout<<vpb[i].first<<" "<<vpb[i].second<<endl;
        // for(int i=0;i<vpa.size();i++)cout<<vpc[i].first<<" "<<vpc[i].second<<endl;        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(vpa[i].second==vpb[j].second or vpa[i].second==vpc[k].second or vpc[k].second==vpb[j].second) continue;
                    else sum=max(sum,vpa[i].first+vpb[j].first+vpc[k].first);
                }
            }
        }
        cout<<sum<<endl;

    }
    return 0;
    }
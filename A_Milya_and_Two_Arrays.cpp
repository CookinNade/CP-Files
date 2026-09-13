#include<bits/stdc++.h>
 
using namespace std;
// typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        set<int> sa; set<int> sb;
        int sarr[n];int sbrr[n];
        for(int i=0; i<n;i++){
            cin>>a;
            sa.insert(a);
            sarr[i]=a;
        }
        for(int i=0; i<n;i++){
            cin>>a;
            sb.insert(a);
            sbrr[i]=a;
        }
        if(sa.size()>=3 or sb.size()>=3){
            cout<<"YES"<<endl;
        }
        else if(sa.size()==2 and sb.size()==2){
            if(accumulate(sarr,sarr+n,0ll)!=accumulate(sarr,sarr+n,0ll)){
                cout<<"YES"<<endl;
            }
            else {
                sort(sarr,sarr+n);sort(sbrr,sbrr+n);
                if(count(sarr,sarr+n,sarr[0])==1 and count(sarr,sarr+n,sarr[0])==1){
                    cout<<"NO"<<endl;
                }
                else if(count(sarr,sarr+n,sarr[n-1])==1 and count(sarr,sarr+n,sarr[n-1])==1){
                    cout<<"NO"<<endl;
                }
                else cout<<"YES"<<endl;
            }
        }
        else cout<<"NO"<<endl;

    }
    return 0;
    }
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x,q; 
    cin>>t;
    string s;
    while (t--){
        set<int>st;
        cin>>n;
        int arr[n];
        for(int i=1;i<=n;i++)cin>>arr[i];
        for(int i=2;i<=n;i++){
            if(arr[i-1]!=arr[i]){
                st.insert(i);
                st.insert(i-1);
            }
        }
        cin>>q;
        while(q--){
            cin>>l>>r;
            auto it=st.upper_bound(l);
            if(*it<r and it!=st.end()){
                if(arr[*it+1]!=arr[*it]){
                    cout<<*it<<" "<<*it+1<<endl;
                }
                else if(arr[*it-1]!=arr[*it]){
                    cout<<*it-1<<" "<<*it<<endl;
                }
                else cout<<-1<<" "<<-1<<endl;
            }
            else if (*it==r and it!=st.end()){
                if(arr[r]!=arr[r-1]){
                    cout<<r-1<<" "<<r<<endl;
                }
                else cout<<-1<<" "<<-1<<endl;
            }
            else cout<<-1<<" "<<-1<<endl;
        }
        cout<<endl;
    }
    return 0;
    }
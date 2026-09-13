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
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        int f=0;
        set<ll>fact;
        for(int i=1;i<n-1;i++){
            if(arr[i]%arr[i-1] and f==0){
                cout<<"dhukse "<<arr[i-1]<<" "<<arr[i]<<endl;
                f++;
                a=arr[i];
                for(int j=2;j*j<=a;j++){
                    if(arr[i]%j==0 and arr[i-1]%j==0){
                        cout<<"dhuklse "<<j<<endl;
                        b=a/j;
                        c=arr[i-1]/j;
                        if(a%c==0){
                            fact.insert(c);
                        }
                        if(arr[i-1]%b==0){
                            c=arr[i-1]/b;
                            if(a%c==0)fact.insert(c);
                        }
                    }
                }
            }
            else if(arr[i]%arr[i-1]){
                for(auto it=fact.begin();it!=fact.end();){
                    a=(*it);
                    if(arr[i]%a==0 and (arr[i]/a)>=arr[i-1] and (arr[i]/a)<=arr[i+1]){
                        ++it;
                    }
                    else it=fact.erase(it);
                }
            }
            
        }
        cout<<fact.size()<<endl;
        auto it = --fact.end();
        cout<<(*it)<<endl;
    }
    return 0;
    }
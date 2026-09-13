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
        unordered_set<int>got;
        unordered_set<int>tofnd;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        c=n;
        cnt=1;
        a=arr[0];
        for(int i=0;i<n;i++){
            got.insert(arr[i]);
            if(i!=0 and arr[i]==a){
                c=i+1;
                cnt++;
                break;
            }
        }
        // if(c>0){
            for(int i=c;i<n;i++){
                auto it = got.find(arr[i]);
                if(it == got.end()){
                    tofnd.insert(arr[i]);
                }
                else if(it!=got.end()){
                    got.erase(arr[i]);
                    tofnd.insert(arr[i]);
                }
                if(got.size()==0){
                    cnt++;
                    got = tofnd;
                    tofnd.clear();
                    // break;
                }
            }
        // }
        cout<<cnt<<endl;


    }
    return 0;
    }
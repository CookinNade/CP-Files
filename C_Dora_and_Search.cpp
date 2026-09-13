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
        int arr[n];
        set<int>baki;
        set<int>ase;
        for(int i=0;i<n;i++){
            cin>>arr[i]; baki.insert(i+1);
        }
        r=n-1;
        l=0;
        for(int i=0;i<n;i++){
            cnt=0;
            // cout<<l<<" "<<r<<" "<<i<<endl;
            auto dan = --baki.end(); auto bam=baki.begin();
            if(arr[l]==*dan or arr[l]==*bam){
                baki.erase(arr[l]); l++;
                if(baki.empty()) break;
                auto dan = --baki.end(); auto bam=baki.begin();
                if(r<=l)break;
            }
            else cnt++;
            if(baki.empty() or r<=l) break;
            auto dan2 = --baki.end(); auto bam2=baki.begin();
            if(arr[r]==*dan2 or arr[r]==*bam2){
                baki.erase(arr[r]); r--;
            }
            else {
                cnt++;
                // cout<<l+1<<" "<<r+1<<endl;
            }
            if(baki.empty()) break;
            if(r<=l)break;
            if(cnt==2)break;
            
        }
        if(cnt==2)cout<<l+1<<" "<<r+1<<endl;
        else cout<<-1<<endl;
    }
    return 0;
    }
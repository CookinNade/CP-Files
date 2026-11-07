#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        vector<int>odd;
        vector<int>even;
        if(n==1){
            cout<<"YES\n";
            continue;
        }
        for(int i=0;i<n;i+=2){
            even.push_back(arr[i]);
        }
        for(int i=1;i<n;i+=2){
            odd.push_back(arr[i]);
        }
        sort(even.rbegin(),even.rend());
        sort(odd.rbegin(),odd.rend());
        int emx = *max_element(even.begin(),even.end());
        int omx = *max_element(odd.begin(),odd.end());
        int big = 0;
        if(omx > emx) big = 1;
        int cnte = 0;
        int cnto = 0;
        int epor = 0;
        int opor = 0;
        for(int i=0;i<(int)even.size()-1;i++){
            // cout<<even[i] <<" "<<even[i+1]<<endl;
            if(even[i] == even[i+1] + 1){
                cnte++;
                epor = max(even[i] , epor);
            }
        }
        for(int i=0;i<(int)odd.size()-1;i++){
            if(odd[i] == odd[i+1] + 1){
                cnto++;
                opor = max(odd[i] , opor);
            }
        }
        if(cnte >= 2 or cnto >= 2)cout<<"NO\n";
        else if(cnte == 1 and cnto == 1){
            if(big and opor < epor)cout<<"YES\n";
            else if(big  == 0 and epor < opor)cout<<"YES\n";
            else cout<<"NO\n";
        }
        else if(cnte == 1 and cnto == 0 and big)cout<<"YES\n";
        else if(cnto == 1 and cnte == 0 and big==0)cout<<"YES\n";
        else if(cnto == 0 and cnte == 0)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    }
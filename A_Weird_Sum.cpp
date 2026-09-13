#include<bits/stdc++.h>
using namespace std;
using ll=long long;

string s1,s2,s3;
string uniq;

ll letter_map[256];
bool used_digits[10];
bool letter_leading[256];
ll cnt=0;


ll build(string &word){
    ll curr=0;
    for(char c:word){
        curr=curr*10 + letter_map[c];
    }
    return curr;
}

void solve(ll idx){

    if(idx==uniq.size()){
        ll val1=build(s1);
        ll val2=build(s2);
        ll val3=build(s3);

        if(val1 + val2 == val3){
            cout<<val1<<" "<<val2<<" "<<val3<<endl;
            cnt++;
        }

        return;
    }

    char curr_letter=uniq[idx];
    for(ll i=0;i<=9;i++){
        if(used_digits[i]) continue;
        if(letter_leading[curr_letter] && i==0) continue;
        
        letter_map[curr_letter]=i;
        used_digits[i]=true;
        solve(idx + 1);
        used_digits[i]=false;
        letter_map[curr_letter]=-1;
    }
}

ll ans(string a,string b,string c){
    s1=a,s2=b,s3=c;
    cnt=0;
    uniq="";

    for(ll i=0;i<256;i++) letter_map[i]=-1;
    for(ll i=0;i<10;i++)    used_digits[i]=false;
    for(ll i=0;i<256;i++)   letter_leading[i]=false;

    bool seen[256]={false};
    string all= s1+s2+s3;

    for(char c:all){
        if(!seen[c]){
            uniq+=c;
            seen[c]=true;
        }
    }

    letter_leading[s1[0]]=true;
    letter_leading[s2[0]]=true;
    letter_leading[s3[0]]=true;

    solve(0);

    return cnt;
}

int main(){
    ll cnt1=ans("COME","GONE","HOMES");
    cout<<cnt1<<endl;
}
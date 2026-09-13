#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define endl "\n"
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
// #define int long long

// Don't Start typing till you complete the idea.

// Check these things for WA and before submitting
// 1. Did you clear all the global arrays
// 2. Did you checked your <= >= < >
// 3. Did you take the input properly. Did you use break or return while taking
// input?
// 4. Did you divide by 0.
// 5. Check array , vector , etc size
// 6. in the while loop did you miss something that would cause infinite loop?
// 7. Did you save your dp?
// 8. Are you trying to use something after deleting it?
// 9. Did you read the problem statement wrong?
// 10. Did you check the constrains of the problem properly
// 11. Did you checked for smaller cases like 1 , 0 , etc
// 12. Is it something to with overflow?
// 13. Did you initialized all the variables properly?
// 14. Did you use the formulas correctly?

// STRESS TESTING !!!!!! STRESS TESTING !!!!!
// STRESS Testing Not working?
// Stress test for multiple cases?
// Stress test for big inputs?
// Stress test for really small inputs?
// Even then if it doesn't work -> Did you wrote the wrong Brute force code

// Check these things if you are not generating ideas
// 1. Did you try thinking it in reverse?
// 2. Read the problem statement again
// 3. Check the constraints again
// 4. Try smaller cases in notebook and try to expand
// 5. Think about invariants
// 6. Think simpler ideas maybe?
// 7. Think brute force and try to get something out of it.
// 8. Maybe take a deep breath and take a break for few minutes and drink some
// water? :3


void GG() {
  ll n, k;
  cin >> n >> k;
  if(k & 1) {
    for(int i = 1; i <= k; i++) cout << n << ' ';
    cout << endl;
    return;
  }
  vector<ll> ans(k + 1);
  for(int i = 1; i <= k - 2; i++) ans[i] = n;
  
  ll sum = n * (k - 2);
  ll xa = 0, xb = 0;
  int cnt = 0;
  for(int i = 30; i >= 0; i--) {
    int xset = (n >> i) & 1;
    if(xset) cnt++;
    if(cnt == 1) {
        if(xset) xa |= (1 << i);
    } else if(cnt >= 2) {
        if(xset) xb |= (1 << i);
        else xa |= (1 << i), xb |= (1 << i);
    }
    // cout << i << ' ' << xa << ' ' << xb << ' ' << xc << endl;
  }
//   ans[k - 2] = xa;
  ans[k - 1] = xa;
  ans[k] = xb;
  sum += xa + xb;
  vector<ll> ans2(k + 1);
//   for(int i = 1; i <= k - 3; i++) ans2[i] = n;
  if(k == 2) {
      for(int i = 1; i <= k; i++) cout << ans[i] << ' ';
      cout << endl;
      return;
  }
  xa = 0, xb = 0;
  ll xc = 0;
  ll sum2 = 0;
  for(int i = 1; i < k; i++) ans2[i] = n;
  cnt = 0;
  int msb = 31 - __builtin_clz(n);
  for(int i = msb - 1; i >= 0; i--) {
    if((n >> i) & 1) {
        cnt++;
        int ad = (1 << i);
        // ad += (ad - 1);
        if(cnt < k) ans2[cnt] ^= ad, ans2[cnt] |= (ad - 1);
    }
  }
  ll totxor = 0;
  for(int i = 1; i < k; i++) sum2 += ans2[i], totxor ^= ans2[i];
  ans2[k] = totxor ^ n;
  sum2 += ans2[k];
//   cout << sum << ' ' << sum2 << endl;
  if(sum2 > sum) {
    for(int i = 1; i <= k; i++) cout << ans2[i] << ' ';
    cout << endl;
  } else {
    for(int i = 1; i <= k; i++) cout << ans[i] << ' ';
    cout << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int ttc = 1;
  cin >> ttc;
  // int cnt=0;
  while (ttc--) {
    // cout<<"Case "<<++cnt<<": ";
    GG();
  }
}
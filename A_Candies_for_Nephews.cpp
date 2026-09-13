#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define endl "\n"
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back

void GG() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> pref(n + 1);
  int cnt[2] = {0, 0};
  for (int i = 1; i <= n; i++) cnt[s[i - 1] - 'a']++;
  if (cnt[0] == cnt[1]) {
    cout << 0 << endl;
    return;
  }
  if (cnt[0] == 0 || cnt[1] == 0) {
    cout << -1 << endl;
    return;
  }
  int lagbe = cnt[0] - cnt[1];
  map<int, vector<int>> vec;
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1];
    if (s[i - 1] == 'a')
      pref[i]++;
    else
      pref[i]--;
    vec[pref[i]].pb(i);
  }
  int ans = n;
  for (int i = 1; i <= n; i++) {
    int ase = pref[i - 1];
    int dorkar = ase + lagbe;
    if (vec.find(dorkar) == vec.end()) continue;
    auto itr = lower_bound(all(vec[dorkar]), i);
    if (itr == vec[dorkar].end()) continue;
    ans = min(ans, (*itr) - i + 1);
  }
  if (ans >= n) {
    cout << -1 << endl;
  } else
    cout << ans << endl;
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
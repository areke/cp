#include <bits/stdc++.h>
using namespace std;
 
 
 
long long dfs(int x, vector<basic_string<int> > & v, vector<long long> & d, vector<long long> & h) {
  if (d[x] != -1) return d[x];
  long long cur = 1;
  for (int n : v[x]) {
    if (h[n] < h[x]) cur = max(cur, 1 + dfs(n, v, d, h));
    else cur = max(cur, dfs(n, v, d, h));
  }
  return d[x] = cur;
}
 
long long dfs2(int x, vector<basic_string<int> > & v, vector<long long> & d, vector<long long> & a, vector<long long> & h) {
  long long cur = 0;
  if (a[x] != -1) return a[x];
  if (d[x] == 1) {
    cur = max(cur, h[x]);
  }
  for (int n : v[x]) {
    if (h[n] < h[x] && d[n] + 1 != d[x]) continue;
    if (h[n] >= h[x] && d[n] != d[x]) continue;
    cur = max(cur, dfs2(n, v, d, a, h));
  }
  return a[x] = cur;
}
 
long long score(long long s, long long e, long long b) {
  return b + e - s;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    vector<basic_string<int> > v(n);
 
    vector<basic_string<int> > r(n);
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      v[x].push_back(y);
      r[y].push_back(x);
    }
    vector<long long> d(n, -1);
    for (int i = 0; i < n; i++) {
      dfs(i, v, d, h);
    }
    long long maxi = 0;
    for (int i = 0; i < n; i++) {
      maxi = max(maxi, d[i]);
    }
    vector<long long> a(n, -1);
    for (int i = 0; i < n; i++) {
      if (!r[i].size()) {
        dfs2(i, v, d, a, h);
      }
    }
    long long ans = (maxi + 1) * k;
    for (int days = maxi; days <= maxi + 1; days++) {
      vector<array<long long, 2> > p;
      long long start = k - 1;
      long long end = 0;
      multiset<long long> s;
      for (int i = 0; i < n; i++) {
        if (r[i].empty() && d[i] == days - 1) {
          p.push_back({h[i], a[i]});
          s.insert(a[i]);
        } else if (r[i].empty() && d[i] == days) {
          start = min(start, h[i]);
          end = max(end, a[i]);
        }
      }
      sort(p.begin(), p.end());
      long long nend = end;
      if (!s.empty()) {
        nend = max(end, *s.rbegin());
      }
      long long res = score(start, nend, (days - 1) * k);
      for (int i = (int) p.size() - 1; i >= 0; i--) {
        
        start = min(start, p[i][0]);
        s.erase(s.find(p[i][1]));
        nend = end;
        if (!s.empty()) {
          nend = max(end, *s.rbegin());
        }
        //cout << days << " " << i << " " << start << " " << nend << endl;
        res = min(res, score(start, nend, (days - 1) * k));
      }
      ans = min(ans, res);
    }
    cout << ans << endl;
 
 
 
  }
 
  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
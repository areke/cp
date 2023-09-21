#include <bits/stdc++.h>
using namespace std;
 
void dfs(int x, vector<basic_string<int> > & v, vector<int> & c, vector<int> & l, int last = -1) {
  c[x] = 1;
  l[x] = last;
  for (int n : v[x]) {
    if (n == last) continue;
    dfs(n, v, c, l, x);
    c[x] += c[n];
  }
}
 
void get(int x, vector<basic_string<int> > & v, vector<int> & a, int last = -1) {
  a.push_back(x);
  for (int n : v[x]) {
    if (n == last) continue;
    get(n, v, a, x);
  }
}
 
void print(vector<basic_string<int> > & v, int n) {
  int cnt = 0;
  vector<array<int ,2> > ans(n - 1);
  for (int i = 0; i < n; i++) {
    for (int j : v[i]) {
      ans[cnt++] = {i + 1, j + 1};
    }
  }
  for (auto &[x, y] : ans) {
    cout << x << ' ' << y << '\n';
  }
}
 
int hsh(int x, vector<basic_string<int> > & v, map<vector<int>, int> & h, int bad, int last = -1) {
  vector<int> c;
  for (int n : v[x]) {
    if (n == last || n == bad) continue;
    c.push_back(hsh(n, v, h, bad, x));
  }
  sort(c.begin(), c.end());
  auto it = h.find(c);
  if (it != h.end()) {  
    return it->second;
  }
  return h[c] = h.size() + 1;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<basic_string<int> > v(n + 1);
  vector<array<int, 2> > edges(n - 1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    edges[i] = {x - 1, y - 1};
  }
  for (auto &[x, y] : edges) {
    v[x].push_back(y);
    v[y].push_back(x);
  }
  if (n == 2) {
    cout << "1 2" << endl;
    return 0;
  }
  vector<int> l(n, -1);
  vector<int> c(n, 0);
  dfs(0, v, c, l);
  map<int, vector<int> > m;
  for (int i = n - 1; i >= 0; i--) {
    m[c[i]].push_back(i);
  }
  map<vector<int>, int> h;
  set<int> s;
  bool found = false;
  set<int> f;
  int r;
  vector<basic_string<int> > res(n);
  vector<int> hh(n);
  for (int i = 0; i < n; i++) {
    hh[i] = hsh(i, v, h, l[i]);
  }
  set<int> tried;
  for (int i = 1; i <= 18; i++) {
    if (found) break;
    s.clear();
    for (int j : m[i + 1]) {
      s.insert(hh[j]);
    }
    for (int j : m[i]) {
      if (found) break;
      if (tried.count(hh[j])) continue;
      tried.insert(hh[j]);
      vector<int> a;
      get(j, v, a, l[j]);
      for (int y : a) {
        v[y].push_back(n);
        if (!s.count(hsh(j, v, h, l[j]))) {
          r = j;
          found = true;
          f.insert(a.begin(), a.end());
          v[y].pop_back();
          for (int ii = 0; ii < n; ii++) {
            if (!f.count(ii)) {
              res[y].push_back(ii);
              for (int iii : f) {
                for (int j : v[iii]) {
                  if (f.count(j) && iii < j) {
                    res[iii].push_back(j);
                  }
                }
              }
              f.insert(ii);
              break;
            }
            
          }
          break;
        }
        v[y].pop_back();
      }
    }
  }
  assert(found); 
  
  vector<int> left;
  for (int i = 0; i < n; i++) {
    if (!f.count(i)) left.push_back(i);
  }
  if (left.size()) {
    res[left[0]].push_back(r);
    for (int i = 1; i < left.size(); i++) {
      res[left[i]].push_back(left[i - 1]);
    }
    r = left.back();
  }
  assert(left.size() + f.size() <= n);
  swap(res[0], res[r]);
 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < res[i].size(); j++) {
      if (res[i][j] == r) res[i][j] = 0;
      else if (res[i][j] == 0) res[i][j] = r;
    }
  }
  print(res, n);
 
  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
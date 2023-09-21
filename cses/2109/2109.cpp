#include <bits/stdc++.h>
using namespace std;
 
struct SANode {
  int len;
  vector<int> next;

  vector<int> w;
  int val = 0;
  int link;
  SANode(int l) {
    len = l;
    link = -1;
    next.assign(26, -1);
    w.assign(26, 0);
  }
};
 
struct SA {
  int n;
  vector<SANode*> v;
  int last = 0;
  int cnt = 0;
 
  int addNode(SANode* node) {
    v[cnt++] = node;
    return cnt - 1;
  }
 
  SA(string s) {
    n = s.length();
    v.assign(2 * n + 5, NULL);
    addNode(new SANode(0));
    for (int i = 0; i < s.length(); i++) {
      int c = s[i] - 'a';
      int p = last;
      auto cur = new SANode(i + 1);
      cur->val = 1;
      int curID = addNode(cur);
      while (p != -1 && v[p]->next[c] == -1) {
        v[p]->next[c] = curID;
        v[p]->w[c]++;
        p = v[p]->link;
      }
      if (p == -1) {
        cur->link = 0;
      } else if (v[p]->next[c] != -1) {
        int q = v[p]->next[c];
        if (v[p]->len + 1 == v[q]->len) {
          cur->link = q;
        } else {
          auto clone = new SANode(v[p]->len + 1);
          clone->next = v[q]->next;
          clone->w = v[q]->w;
          clone->link = v[q]->link;
          int cloneID = addNode(clone); 
          v[q]->link = cloneID;
          cur->link = cloneID;
          int lst = p;
          while (lst != -1 && v[lst]->next[c] == q) {
            v[lst]->next[c] = cloneID;
            lst = v[lst]->link;
          }
        }
      } else {
        assert(false);
      }
      last = curID;
    }
  }
};
 
long long solve(int x, SA & a, vector<long long> & c, vector<long long> & cnt) {
  if (c[x] != -1) return c[x];
  long long cur = cnt[x];
  bool found = false;
  for (int n : a.v[x]->next) {
    if (n == -1)continue;
    found = true;
    cur += solve(n, a, c, cnt);
  }
  return c[x] = cur;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  
  auto at = SA(s);
  long long k;
  cin >> k;
  vector<long long> cnt(at.cnt, 0);
  vector<pair<int, int> > v;
  for (int i = 0; i < at.cnt; i++) {
    v.push_back({at.v[i]->len, i});
    cnt[i] = at.v[i]->val;
  }
  sort(v.begin(), v.end());
  for (int i = v.size() - 1; i >= 1; i--) {
    cnt[at.v[v[i].second]->link] += cnt[v[i].second]; 
  }
  cnt[0] = 0;
  vector<long long> c(at.cnt, -1);
  solve(0, at, c, cnt);
  int cur = 0;
  long long num = 0;
  string res = "";
  bool found = true;
  while (found) {
    found = false;
    if (num >= k) break;
    int last = cur;
    for (int i = 0; i < 26; i++) {
      //cout << cur << " " << i << " " << at.v[cur]->next[i] << endl;
      if (at.v[cur]->next[i] == -1) continue;
      if (num + c[at.v[cur]->next[i]] >= k) {
        found = true;
        res += (i + 'a');
        
        cur = at.v[cur]->next[i];
        num += cnt[cur];
        break;
      } else {
        num += c[at.v[cur]->next[i]];
      }
    }
  }
  cout << res << endl;
 
 
 
  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct SANode {
  int len;
  vector<int> next;
  int val = 0;
  int link;
  SANode(int l) {
    len = l;
    link = -1;
    next.assign(26, -1);
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

long long solve(int x, SA & a, vector<long long> & c) {
  if (c[x] != -1) return c[x];
  long long cur = 1;
  bool found = false;
  for (int n : a.v[x]->next) {
    if (n == -1)continue;
    found = true;
    cur += solve(n, a, c);
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
  vector<long long> c(at.cnt, -1);
  solve(0, at, c);
  int cur = 0;
  long long num = 0;
  string res = "";
  bool found = true;
  while (found) {
    found = false;
    if (num == k) break;
    for (int i = 0; i < 26; i++) {
      if (at.v[cur]->next[i] == -1) continue;
      if (num + c[at.v[cur]->next[i]] >= k) {
        found = true;
        res += (i + 'a');
        cur = at.v[cur]->next[i];
        break;
      } else {
        num += c[at.v[cur]->next[i]];
      }
    }
    num++;
  }
  cout << res << endl;



  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}

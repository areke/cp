#include <bits/stdc++.h>
using namespace std;

struct SANode {
  int len;
  vector<int> next;
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    
  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}

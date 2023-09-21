#include <bits/stdc++.h>
using namespace std;
struct SANode {
  int len;
  int val;
  vector<int> next;
  int link;
  SANode(int l) {
    len = l;
    link = -1;
    val = 0;
    next.assign(26, -1);
  }
};
 
struct SA {
  int n;
  vector<SANode*> v;
  int last = 0;
  int cnt = 0;
  int end = 0;

  int addNode(SANode* node) {
    v[cnt++] = node;
    return cnt - 1;
  }

  SA(string s) {
    n = s.length();
    v.assign(2 * n + 5, NULL);
    addNode(new SANode(-1));
    for (int i = 0; i < s.length(); i++) {
      int c = s[i] - 'a';
      int p = last;
      auto cur = new SANode(i);
      int curID = addNode(cur);
      cur->val = 1;
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
      end = curID;
      last = curID;
    }
  }
};

int dfs(int x, SA & at, vector<vector<int> > & v, vector<int> & res) {
  if (res[x] != -1) return res[x];
  int cur = at.v[x]->val;
  for (int n : v[x]) {
    cur += dfs(n, at, v, res);
  }
  return res[x] = cur;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
  cin >> s;
  int q;
  cin >> q;
  auto at = SA(s);
  vector<vector<int> > v(at.cnt);
  for (int i = 0; i < at.cnt; i++) {
    if (at.v[i]->link != -1) {
      v[at.v[i]->link].push_back(i);
    }
  }
  vector<int> res(at.cnt, -1);
  dfs(0, at, v, res);
  while (q--) {
    string t;
    cin >> t;
    int cur = 0;
    bool can = true;
    for (int i = 0; i < t.length(); i++) {
      if (at.v[cur]->next[t[i] - 'a'] == -1) {
        can = false;
        break;
      }
      cur = at.v[cur]->next[t[i] - 'a'];
    }
    if (can) {
      cout << res[cur] << endl;
    } else {
      cout << 0 << endl;
    }
  }


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}

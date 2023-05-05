#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

bool isLower(string & s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] < 'a' || s[i] > 'z') {
      return false;
    }
  }
  return true;
}

void dfs(string x, map<string, vector<string> > & e, set<vector<string> > & vis, vector<string> path, int & res, bool has) {
  
  if (isLower(x)) {
    int cnt = 0;
    map<string, int> m;
    for (int i = 0; i< path.size(); i++) {
      if (path[i] == x) cnt++;
    }
    if (x == "start") {
      if (cnt >= 1) return;
    }
    if (cnt >= 1) {
      if (has) return;
      has = true;
    }

  }
  path.push_back(x);
  if (vis.find(path) != vis.end()) return;
  vis.insert(path);
  if (x == "end") {
    res++;
    if (res % 100 == 0) {
      cout << res << endl;
    }
    return;
  }
  for (int i = 0; i < e[x].size(); i++) {
    dfs(e[x][i], e, vis, path, res, has);
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  map<string, vector<string> > e;
  int res = 0;
  for (int i = 0; i < 25; i++) {
    string s;
    cin >> s;
    vector<string> v;
    string t = "";
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == '-') {
        v.push_back(t);
        t = "";
      } else {
        t += s[j];
      }
    }

    v.push_back(t);
    e[v[0]].push_back(v[1]);
    e[v[1]].push_back(v[0]);
  }
  set<vector<string> > path;

  for (auto it : e) {
    dfs("start", e, path, {}, res, false);
  }
  cout << res << endl;
	return 0;
}

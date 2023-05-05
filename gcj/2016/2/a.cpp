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

string solve(int n, int r, int p, int s) {
  if (n == 1) {
    if (p == 1 && r == 1) {
      return "PR";
    } else if (p == 1 && s == 1) {
      return "PS";
    } else if (r == 1 && s == 1) {
      return "RS";
    }
    return "IMPOSSIBLE";
  }
  int on = n;
  n = pow(2, n);
  int left = n / 2 - p;

  if (left < 0) {
    return "IMPOSSIBLE";
  }
  int nr = 0, np = 0, ns = 0;
  nr = (n - 2 * p) / 2;
  r -= nr;
  s -= nr;

  if (r < 0 || s < 0) {
    return "IMPOSSIBLE";
  }

  np = r;
  ns = s;
  string next = solve(on - 1, nr, np, ns);
  if (next == "IMPOSSIBLE") return next;
  string ret = "";
  // p < r < s
  // PS -> PRPS
  // PR -> PRRS
  // RS -> PRPSPSRS
  for (char c : next) {
    if (c == 'S') ret += "PS";
    if (c == 'R') ret += "RS";
    if (c == 'P') ret += "PR";
  }
  //cout << n << " " << ret << endl;
  return ret;

}

string best(string & valid) {
  if (valid.length() == 1) return valid;
  vector<string> v = {valid.substr(0, valid.length() / 2), valid.substr(valid.length() / 2, valid.length() / 2)};
  for (int i = 0; i < 2; i++) {
    v[i] = best(v[i]);
  }
  sort(v.begin(), v.end());
  string res = "";
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < v[i].length(); j++) {
      res += v[i][j];
    }
  }
  //cout << best[0] << " " << best[1] << " " << res << endl;
  return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
  int curtest= 1;
	while (tests--) {
    cout << "Case #" << curtest <<": ";
    curtest++;
		int n, r, p, s;
    cin >> n >> r >> p >> s;
    string valid = solve(n, r, p , s);
    if (valid == "IMPOSSIBLE") {
      cout << valid << endl;
      continue;
    }
    cout << best(valid) << endl;
   

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}

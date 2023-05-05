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
long long solve(string & s) {

  vector<int> alpha(26, 0);
  for (int i = 0; i < s.length(); i++) {
    alpha[s[i] - 'A']++;
  }
  sort(alpha.begin(), alpha.end());
  long long res = alpha[25];
  cout << alpha[25] << endl;
  for (int i =0; i < 26; i++) {
    if (alpha[i]) {
      res-= alpha[i];
      break;
    }
  }
  return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  string s;
  cin >> s;
  map<string, char> m;

  map<string, long long> res;
  for (int i = 0; i < 100; i++) {
    string ss;
    char c;
    cin >> ss >> c;
    m[ss] = c;
  }
  for (int i = 1; i < s.length(); i++) {
    string t = s.substr(i - 1, 2);
    //cout <<t << endl;
    res[t]++;
  }
  cout << res.size() << endl;
  for (int st = 0; st < 40 ;st++) {
    map<string, long long> next;
    for (auto it : res) {
      //cout << it.first << endl;
      if (!m.count(it.first)) continue;
      char c = m[it.first];
      string a = {it.first[0], c};
      string b = {c, it.first[1]};
      cout << it.first << " " << a << " " << b << endl;
      next[a] += it.second;
      next[b] += it.second;
    }
    res = next;
  }
  vector<long long> alpha(26, 0);
  for (auto it : res) {
    for (char c : it.first) {
      alpha[c - 'A'] += it.second;
    }
  }
  alpha[s[0] - 'A']++;
  alpha[s[s.length() - 1] - 'A']++;
  sort(alpha.begin(), alpha.end());
  long long ans = alpha[25];
  cout << alpha[25] << endl;
  for (int i = 0; i < 26; i++) {
    if (alpha[i]) {
      ans -= alpha[i];
      break;
    }
  }
  cout << ans / 2 << endl;
	return 0;
}

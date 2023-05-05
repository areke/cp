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

vector<char> open = {'(', '[', '{', '<'};
vector<char> closed = {')', ']', '}', '>'};
vector<long long> scores = {3, 57, 1197, 25137};

int search(char c, vector<char> v) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == c) return i;
  }
  return -1;
}

long long solve(string & s) {
  stack<char> st;
  for (int i = 0; i < s.length(); i++) {
    if (search(s[i], open) != -1) {
      st.push(s[i]);
    } else {
      if (st.empty()) {
        return scores[search(s[i], closed)];
      }
      char last = st.top();
      if (search(last, open) != search(s[i], closed)) {
        return scores[search(s[i], closed)];
      }
      st.pop();
    }
  }
  long long res = 0;
  while (!st.empty()) {
    char last = st.top();
    st.pop();
    res *= 5;
    res += search(last, open) + 1;
  }
  return res * -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  string line;
  long long x = 0, y = 0, z = 0;
  long long res = 0;
  vector<long long> v;
  while (getline(cin, line)) {
      stringstream ss(line);
      string s;
      ss >> s;
      x = solve(s);
      if (x < 0) {
        v.push_back(abs(x));
      }
  }
  sort(v.begin(), v.end());
  cout << v[v.size() / 2] << endl;
	return 0;
}

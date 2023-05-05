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

vector<string> split(string s, char c) {
  string t = "";
  vector<string> res;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ',') {
      res.push_back(t);
      t = "";
    } else {
      t += s[i];
    }
  }
  res.push_back(t);
  return res;
}

long long done(vector<vector<int> > &  v, set<int> & s) {
  bool ret = false;
  for (int i = 0; i < 5; i++) {
    bool f = true;
    for (int j = 0; j < 5; j++) {
      f &= s.find(v[i][j]) != s.end();
    }
    ret |= f;
  }
  for (int i = 0; i < 5; i++) {
    bool f = true;

    for (int j = 0; j < 5; j++) {
      f &= s.find(v[j][i]) != s.end();
    }
    ret |= f;
  }
  bool f = true;
  for (int i = 0; i < 5; i++) {
    f &= s.find(v[i][i]) != s.end();
  }
  ret |= f;
  f = true;
  for (int i = 0; i < 5; i++) {
    f &= s.find(v[i][5 - i]) != s.end();
  }
  ret |= f;
  return ret;
}

long long score(vector<vector<int> > & v, set<int> & s) {
  long long res = 0;
  for (int i = 0; i < 5; i++) {
    for (int j =0 ; j < 5; j++) {
      if (s.find(v[i][j]) == s.end()) {
        res += v[i][j];
      }
    }
  }
  return res;
}


int main() {
    string line;
    long long x = 0, y = 0, z = 0;
    long long res = 0;
    string s, t;
    int numLines = 0;
    cin >> line;
    vector<string> v = split(line, ',');
    vector<int> vi(v.size());
    for (int i = 0; i < v.size(); i++) {
      vi[i] = stoi(v[i]);
    }
    cout << endl;
    vector<vector<vector<int> > > b;
    for (int k = 0; k < 100; k++) {
      vector<vector<int> > board(5, vector<int>(5, 0));
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          cin >> board[i][j];

        }
      }
      b.push_back(board);
    }
    set<int> cur;
    set<int> won;
    res = 0;
    for (int i = 0; i < vi.size(); i++) {
      cur.insert(vi[i]);
      for (int j = 0; j < b.size(); j++) {
        if (done(b[j], cur)) {
          won.insert(j);
          if (won.size() == b.size()) {
            res = score(b[j], cur) *
          }
        }
      }
      if (res) break;

    }
    cout << numLines << endl;
    cout << res << endl;
    
	return 0;
}
